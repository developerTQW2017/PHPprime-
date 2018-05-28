TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bankaccount.cpp \
    moneymarketaccount.cpp \
    cdaccount.cpp

HEADERS += \
    bankaccount.h \
    moneymarketaccount.h \
    cdaccount.h
