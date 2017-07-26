TEMPLATE	= app
TARGET		= udpserver

CONFIG		+= qt warn_on release
DEPENDPATH	= ../../include

HEADERS		= udpserver.h
SOURCES		= udpserver.cpp \
		  main.cpp
TRANSLATIONS  = udpserver_zh.ts
QT += network