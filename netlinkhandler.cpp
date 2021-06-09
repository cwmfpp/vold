
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <android-base/logging.h>//cwm del
#include "log.h"
#include "netlinkevent.h"
#include "netlinkhandler.h"
//#include "VolumeManager.h" //cwm del todo


NetlinkHandler::NetlinkHandler(int listenerSocket) : NetlinkListener(listenerSocket) {}

NetlinkHandler::~NetlinkHandler() {}

int NetlinkHandler::start() {
    return this->startListener();
}

int NetlinkHandler::stop() {
    return this->stopListener();
}

void NetlinkHandler::onEvent(NetlinkEvent* evt) {
    const char* subsys = evt->getSubsystem();

    if (!subsys) {
        SLOGV("chenwenmin No subsystem found in netlink event");//cwm mod
        return;
    }

    SLOGV("chenwenmin subsys=%s", subsys);
    if (std::string(subsys) == "block") {
        SLOGV("chenwenmin block");//
        //vm->handleBlockEvent(evt);//cwm del todo
    }

#if 0
    //VolumeManager* vm = VolumeManager::Instance();//cwm del todo
    const char* subsys = evt->getSubsystem();

    if (!subsys) {
        //SLOGV(WARNING, "No subsystem found in netlink event");//cwm mod
        return;
    }

    if (std::string(subsys) == "block") {
        //vm->handleBlockEvent(evt);//cwm del todo
    }
#endif
}

