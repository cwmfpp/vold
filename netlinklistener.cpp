
#define LOG_TAG "NetlinkListener"

#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <linux/netlink.h> /* out of order because must follow sys/socket.h */

//#include <cutils/uevent.h> //cwm del
#include "log.h" //cwm mod
#include "netlinkevent.h"
//#include <utils/CallStack.h>
//#include "netlinklistener.h"

#if 1
/* temporary version until we can get Motorola to update their
 * ril.so.  Their prebuilt ril.so is using this private class
 * so changing the NetlinkListener() constructor breaks their ril.
 */
NetlinkListener::NetlinkListener(int socket) :
                            SocketListener(socket, false) {
    mFormat = NETLINK_FORMAT_ASCII;
}
#endif

NetlinkListener::NetlinkListener(int socket, int format) :
                            SocketListener(socket, false), mFormat(format) {
}


ssize_t uevent_kernel_recv(int socket, void* buffer, size_t length, bool require_group, uid_t* uid) {
    struct iovec iov = {buffer, length};
    struct sockaddr_nl addr;
    char control[CMSG_SPACE(sizeof(struct ucred))];
    struct msghdr hdr = {
        &addr, sizeof(addr), &iov, 1, control, sizeof(control), 0,
    };
    struct ucred* cred;

    *uid = -1;
    ssize_t n = TEMP_FAILURE_RETRY(recvmsg(socket, &hdr, 0));
    if (n <= 0) {
        return n;
    }

    struct cmsghdr* cmsg = CMSG_FIRSTHDR(&hdr);
    if (cmsg == NULL || cmsg->cmsg_type != SCM_CREDENTIALS) {
        /* ignoring netlink message with no sender credentials */
        goto out;
    }

    cred = (struct ucred*)CMSG_DATA(cmsg);
    *uid = cred->uid;

    if (addr.nl_pid != 0) {
        /* ignore non-kernel */
        goto out;
    }
    if (require_group && addr.nl_groups == 0) {
        /* ignore unicast messages when requested */
        goto out;
    }

    return n;

out:
    /* clear residual potentially malicious data */
    bzero(buffer, length);
    errno = EIO;
    return -1;
}

bool NetlinkListener::onDataAvailable(SocketClient *cli)
{
    int socket = cli->getSocket();
    ssize_t count;
    uid_t uid = -1;

    bool require_group = true;


#if 0
            SLOGE("%d %s chenwenmin \n", __LINE__, __FUNCTION__);
          android::CallStack callstack;
          callstack.update();
          callstack.dump(1);
          //callstack.log("callstack-tag-display", ANDROID_LOG_DEBUG, "  ");
          callstack.log("callstack-tag-FrameworkListener");
            SLOGE("%d %s chenwenmin \n", __LINE__, __FUNCTION__);
#endif

    if (mFormat == NETLINK_FORMAT_BINARY_UNICAST) {
        require_group = false;
    }

    count = TEMP_FAILURE_RETRY(uevent_kernel_recv(socket,
            mBuffer, sizeof(mBuffer), require_group, &uid));
    if (count < 0) {
        SLOGE("recvmsg failed (%s)", strerror(errno));
        return false;
    }

    NetlinkEvent *evt = new NetlinkEvent();
    if (evt->decode(mBuffer, count, mFormat)) {
        onEvent(evt);
    } else if (mFormat != NETLINK_FORMAT_BINARY) {
        // Don't complain if parseBinaryNetlinkMessage returns false. That can
        // just mean that the buffer contained no messages we're interested in.
        SLOGE("Error decoding NetlinkEvent");
    }

    delete evt;
    return true;
}
