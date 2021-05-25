#ifndef NETLINKMANAGER_H
#define NETLINKMANAGER_H


class NetlinkManager
{

private:
  static NetlinkManager* sInstance;
  int mSock;

public:
    NetlinkManager();
    virtual ~NetlinkManager();
    int start();

    static NetlinkManager* Instance();
};

#endif // NETLINKMANAGER_H
