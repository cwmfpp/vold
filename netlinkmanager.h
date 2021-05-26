#ifndef NETLINKMANAGER_H
#define NETLINKMANAGER_H


#include "netlinkhandler.h" //cwm add

class NetlinkManager
{

private:
  static NetlinkManager* sInstance;
  NetlinkHandler* mHandler;
  int mSock;

public:
    NetlinkManager();
    virtual ~NetlinkManager();
    int start();

    static NetlinkManager* Instance();
};

#endif // NETLINKMANAGER_H
