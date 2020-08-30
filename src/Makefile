# --------------------------------------------------------------------------------
#   (C) Aditya V. Nebhrajani 2020
#   File: Makefile 
#   Description: Makefile for generic linked list library.

# ---------------------------------RCS/CVS----------------------------------------
#   $Id: Makefile,v 1.1 2020/05/31 10:32:30 aditya Exp $
#   $Author: aditya $
#   $Source: /auto/common/.cvsroot/libll/src/Makefile,v $
#   $Revision: 1.1 $
#   $Date: 2020/05/31 10:32:30 $
#   $Log: Makefile,v $
#   Revision 1.1  2020/05/31 10:32:30  aditya
#   Initial commit.
#
# --------------------------------------------------------------------------------

libll.so: libll.c libll.h 
	gcc -c -Wall -fpic ../src/libll.c
	gcc -shared -o libll.so libll.o 

install:
	cp -f libll.so /auto/common/lib 

clean:
	rm -f libll.so

clobber:
	rm -f *.o *.so *~
