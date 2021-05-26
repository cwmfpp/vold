#ifndef NETLINKHANDLER_H
#define NETLINKHANDLER_H

#include "netlinklistener.h"

class NetlinkHandler : public NetlinkListener {
  public:
    explicit NetlinkHandler(int listenerSocket);
    virtual ~NetlinkHandler();

    int start(void);
    int stop(void);

  protected:
    virtual void onEvent(NetlinkEvent* evt);
};

#endif // NETLINKHANDLER_H
