TEMPLATE = app
CONFIG += console c++20
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        src/main.cpp

HEADERS += \
         src/property.h
INCLUDEPATH += \
            lib \
            src \
