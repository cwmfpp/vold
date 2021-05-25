#ifndef SOCKETLISTENER_H
#define SOCKETLISTENER_H


#include <pthread.h>

#include <unordered_map>
#include <vector>

#include "socketclient.h"
//#include "SocketClientCommand.h"

class SocketListener {
    bool                    mListen; //是否需要listen
    const char              *mSocketName;
    int                     mSock;
    std::unordered_map<int, SocketClient*> mClients;
    pthread_mutex_t         mClientsLock;
    int                     mCtrlPipe[2];
    pthread_t               mThread;
    bool                    mUseCmdNum;

public:
    SocketListener(const char *socketName, bool listen);
    SocketListener(const char *socketName, bool listen, bool useCmdNum);
    SocketListener(int socketFd, bool listen);

    virtual ~SocketListener();
    int startListener();
    int startListener(int backlog);
    int stopListener();

    void sendBroadcast(int code, const char *msg, bool addErrno);

    //void runOnEachSocket(SocketClientCommand *command); //todo

    bool release(SocketClient *c) { return release(c, true); }

protected:
    virtual bool onDataAvailable(SocketClient *c) = 0;

private:
    static void *threadStart(void *obj);

    // Add all clients to a separate list, so we don't have to hold the lock
    // while processing it.
    std::vector<SocketClient*> snapshotClients();

    bool release(SocketClient *c, bool wakeup);
    void runListener();
    void init(const char *socketName, int socketFd, bool listen, bool useCmdNum);
};

#endif // SOCKETLISTENER_H
