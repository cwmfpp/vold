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
    logging.h \
    netlinkevent.h \
    netlinklistener.h \
    netlinkmanager.h \
    socketclient.h \
    socketlistener.h
