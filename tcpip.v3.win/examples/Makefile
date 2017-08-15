#
# Internetworking with TCP/IP, Volume III example code Makefile
#
#	David L Stevens, Internetworking Research Group at Purdue
#	Tue Sep 17 19:40:42 EST 1991
#

INCLUDE =

CLNTS = TCPecho TCPdtc TCPtecho UDPecho UDPtime
SERVS = TCPdtd TCPechod TCPmechd UDPtimed daytimed
OTHER = superd 

DEFS = #-D_BSD_SOURCE
CFLAGS = -W -pedantic -ansi -g ${DEFS} ${INCLUDE}

LIBS = -lwsock32 -lws2_32

HDR =
CSRC = TCPecho.c TCPdtc.c TCPtecho.c UDPecho.c UDPtime.c
CXSRC = conTCP.c conUDP.c consock.c errexit.c

SSRC = TCPdtd.c TCPechod.c TCPmechd.c UDPtimed.c \
	daytimed.c superd.c
SXSRC = passTCP.c passUDP.c passsock.c sv_funcs.c

CXOBJ = conTCP.o conUDP.o consock.o errexit.o
SXOBJ = passTCP.o passUDP.o passsock.o errexit.o

PROGS = ${CLNTS} ${SERVS} ${OTHER}

all: ${PROGS}

${CLNTS}: ${CXOBJ} 
	${CC} -o $@ ${CFLAGS} $@.o ${CXOBJ} ${LIBS}

${SERVS}: ${SXOBJ}
	${CC} -o $@ ${CFLAGS} $@.o ${SXOBJ} ${LIBS}

superd: ${SXOBJ} superd.o sv_funcs.o
	${CC} -o $@ ${CFLAGS} $@.o ${SXOBJ} sv_funcs.o ${LIBS}

clients: ${CLNTS}
servers: ${SERVS}

clean: FRC
	rm -f Makefile.bak a.out core errs lint.errs ${PROGS} *.o

depend: ${HDR} ${CSRC} ${SSRC} ${TNSRC} FRC
	maketd -a ${DEFS} ${INCLUDE} ${CSRC} ${SSRC} ${TNSRC}

install: all FRC
	@echo "Your installation instructions here."

lint: ${HDR} ${XSRC} ${CSRC} ${SSRC} FRC
	lint ${DEFS} ${INCLUDE} ${CSRC} ${SSRC} ${CXSRC} ${SXSRC}

print: Makefile ${SRC} FRC
	lpr Makefile ${CSRC} ${SSRC} ${CXSRC} ${SXSRC}

spotless: clean FRC
	rcsclean Makefile ${HDR} ${SRC}

tags: ${CSRC} ${SSRC} ${CXSRC} ${SXSRC}
	ctags ${CSRC} ${SSRC} ${CXSRC} ${SXSRC}

${HDR} ${CSRC} ${CXSRC} ${SSRC} ${SXSRC}:
	co $@

TCPecho: TCPecho.o
TCPdtc: TCPdtc.o
TCPtecho: TCPtecho.o
UDPecho: UDPecho.o
UDPtime: UDPtime.o
TCPdtd: TCPdtd.o
TCPechod: TCPechod.o
TCPmechd: TCPmechd.o
UDPtimed: UDPtimed.o
daytimed: daytimed.o
superd: superd.o

FRC:
	
# DO NOT DELETE THIS LINE - maketd DEPENDS ON IT
