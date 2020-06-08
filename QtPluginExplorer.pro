# Copyright 2015-2020 Pascal COMBES <pascom@orange.fr>
#
# This file is part of QtPluginExplorer.
#
# QtPluginExplorer is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# QtPluginExplorer is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with QtPluginExplorer. If not, see <http://www.gnu.org/licenses/>

TEMPLATE = app
TARGET = qtpluginexplorer

QT += core
QT -= gui
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp

OTHER_FILES +=  \
    README.md   \
    LICENSE     \

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
