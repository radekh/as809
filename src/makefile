#########################################################
#							#
#	MC6800/6801/6803/6809 cross assembler		#
#							#
#	flags						#
#		MC6809	for MC6809 assembler		#
#							#
#########################################################
# $Header: /home/radek/sync/src/as09/src/makefile,v 1.2 2015/07/14 22:02:42 radek Exp radek $
#
# $Log: makefile,v $
# Revision 1.2  2015/07/14 22:02:42  radek
# Binary renamed to as809 to avoid conflict with similar programs.
#


#CFLAGS = -O
CFLAGS = -O -DMC6809

#AS68 = as68
AS68 = as809

#DESTDIR=/usr/local/bin
DESTDIR=~/bin

all: $(AS68)

$(AS68): as68.o optab.o
	$(CC) $(CFLAGS) -o $(AS68) as68.o optab.o

as68.o obtab.o:	as68.h

lint: as68.h as68.c optab.c
	lint -DMC6809 as68.c optab.c >lint

shar:
	shar COPYRIGHT MANIFEST README makefile as68.h as68.c optab.c >as68.shar

clean:
	rm -f $(AS68) as68.o optab.o lint

install: $(AS68)
	cp $(AS68) $(DESTDIR)/$(AS68)
