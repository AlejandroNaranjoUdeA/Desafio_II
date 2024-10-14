TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        estaciondeservicio.cpp \
        main.cpp \
        surtidor.cpp \
        tanque.cpp \
        transaccion.cpp

HEADERS += \
    estaciondeservicio.h \
    surtidor.h \
    tanque.h \
    transaccion.h
