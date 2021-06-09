#include <iostream>

#include <unistd.h>

#include "netlinkmanager.h"
#include "test.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    NetlinkManager* nm;

    if (!(nm = NetlinkManager::Instance())) {
        cout << "Unable to create NetlinkManager" << endl;
        //exit(1);
    }

    cout << "Instance ok" << endl;
    if (nm->start()) {
        //PLOG(ERROR) << "Unable to start NetlinkManager";
        //exit(1);
    }

    test();

    while (1) {
        sleep(1);
    }
    return 0;
}
