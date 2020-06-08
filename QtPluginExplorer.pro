TEMPLATE = app
TARGET = qtpluginexplorer

QT += core
QT -= gui
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp

# Changing output directories:
win32 {
    OBJECTS_DIR = ./.obj_win
    CONFIG(debug, debug|release):DESTDIR = ./debug
    else:DESTDIR = ./release
}
unix {
    OBJECTS_DIR = ./.obj_unix
    CONFIG(debug, debug|release):DESTDIR = ./debug
    else:DESTDIR = ./release

    target.path=$$(HOME)/bin
}

INSTALLS += target
