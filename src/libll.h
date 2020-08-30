/*------------------------------------------------------------------------------
  (C) Aditya V. Nebhrajani 2020
  File: libll.h
  Description: Header for generic linked list library.

---------------------------------RCS/CVS----------------------------------------
  $Id: libll.h,v 1.4 2020/05/31 13:37:22 aditya Exp $
  $Author: aditya $
  $Source: /auto/common/.cvsroot/libll/src/libll.h,v $
  $Revision: 1.4 $
  $Date: 2020/05/31 13:37:22 $
  $Log: libll.h,v $
  Revision 1.4  2020/05/31 13:37:22  aditya
  Final version.

  Revision 1.3  2020/05/30 16:18:40  aditya
  Latest stable version.

  Revision 1.2  2020/05/27 04:17:40  aditya
  Added function prototypes for llsort, llappend.

  Revision 1.1  2020/05/25 09:34:43  aditya
  Initial version.

------------------------------------------------------------------------------*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
  Linked list data structure.
------------------------------------------------------------------------------*/
typedef struct llnode {
  void *_data;
  struct llnode *_next;
} ll;

/*------------------------------------------------------------------------------
  Function prototypes.
------------------------------------------------------------------------------*/
extern ll *_llcreate(void);

extern ll *lladd(ll *, void *);

extern void llprint(ll *, char *(*)(void *));

extern ll *llsearch(ll *, int, int (*)(void *, int));

extern ll *_lldelete(ll *, void *);

extern ll *llappend(ll *, ll *);

extern ll *llsort(ll *, int (*)(void *, void *));

extern void llprint_single(ll *, char *(*)(void *));

extern ll *lldelete(ll *, int, int (*)(void *, int), void (*)(void *));

extern int llwhich(ll *, int, int (*)(void *, int));

extern void lldestroy(ll *, void (*)(void *));

