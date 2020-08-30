# --------------------------------------------------------------------------------
#   (C) Aditya V. Nebhrajani 2020
#   File: Makefile 
#   Description: Makefile for generic linked list library test.

# ---------------------------------RCS/CVS----------------------------------------
#   $Id: Makefile,v 1.2 2020/05/31 10:37:38 aditya Exp $
#   $Author: aditya $
#   $Source: /auto/common/.cvsroot/libll/test/Makefile,v $
#   $Revision: 1.2 $
#   $Date: 2020/05/31 10:37:38 $
#   $Log: Makefile,v $
#   Revision 1.2  2020/05/31 10:37:38  aditya
#   Stable version.
#
#   Revision 1.1  2020/05/31 10:33:10  aditya
#   Initial commit.
#
# --------------------------------------------------------------------------------

CC = gcc
CCARGS = -Wall -L/auto/common/lib 

lltest:	libll_test.c
	$(CC) $(CCARGS) -o lltest libll_test.c -lll

clean:	
	rm -rf lltest

clobber: 
	 rm -rf *.o lltest *~
