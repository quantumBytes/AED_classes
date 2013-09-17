TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    headers/c_list.cpp \
    headers/nodo.cpp \
    headers/DList.cpp \
    file_mng/file_managing.cpp

HEADERS += \
    headers/nodo.h \
    headers/Dlist.h \
    headers/c_list.h \
    headers/Stack.h \
    headers/Queue.h \
    file_mng/file_managing.h \
    headers/container.h \
    headers/BinTree.h
