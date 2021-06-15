TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread

SOURCES += \
        disk.cpp \
        logging.cpp \
        main.cpp \
        netlinkevent.cpp \
        netlinkhandler.cpp \
        netlinklistener.cpp \
        netlinkmanager.cpp \
        partition.cpp \
        socketclient.cpp \
        socketlistener.cpp \
        storagemanager.cpp \
        test.cpp

HEADERS += \
    disk.h \
    log.h \
    log.h \
    logging.h \
    netlinkevent.h \
    netlinkhandler.h \
    netlinklistener.h \
    netlinkmanager.h \
    partition.h \
    socketclient.h \
    socketlistener.h \
    storagemanager.h \
    test.h

DISTFILES += \
    README.md \
    vold.pro.user
