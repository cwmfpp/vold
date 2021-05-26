TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread

SOURCES += \
        logging.cpp \
        main.cpp \
        netlinkevent.cpp \
        netlinklistener.cpp \
        netlinkmanager.cpp \
        socketclient.cpp \
        socketlistener.cpp

HEADERS += \
    log.h \
    log.h \
    logging.h \
    netlinkevent.h \
    netlinkhandler.h \
    netlinkhandler.h \
    netlinklistener.h \
    netlinkmanager.h \
    socketclient.h \
    socketlistener.h

DISTFILES += \
    README.md \
    vold.pro.user
