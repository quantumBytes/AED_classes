TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    headers/c_list.cpp \
    headers/nodo.cpp \
    headers/DList.cpp

HEADERS += \
    headers/nodo.h \
    headers/Dlist.h \
    headers/c_list.h \
    headers/Stack.h \
    headers/Queue.h
