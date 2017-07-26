TEMPLATE	= app
TARGET		= udpclient

CONFIG		+= qt warn_on release
DEPENDPATH	= ../../include

HEADERS		= udpclient.h
SOURCES		= udpclient.cpp \
		  main.cpp
TRANSLATIONS  = udpclient_zh.ts
QT += network