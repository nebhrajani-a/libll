/*------------------------------------------------------------------------------
  (C) Aditya V. Nebhrajani 2020
  File: libll_test.c 
  Description: Testing for generic linked list library.

---------------------------------RCS/CVS----------------------------------------
  $Id: libll_test.c,v 1.6 2020/05/31 13:37:58 aditya Exp $
  $Author: aditya $
  $Source: /auto/common/.cvsroot/libll/test/libll_test.c,v $
  $Revision: 1.6 $
  $Date: 2020/05/31 13:37:58 $
  $Log: libll_test.c,v $
  Revision 1.6  2020/05/31 13:37:58  aditya
  Final version.

  Revision 1.5  2020/05/30 16:19:02  aditya
  Latest stable release.

  Revision 1.4  2020/05/27 04:54:10  aditya
  Final release.

  Revision 1.3  2020/05/27 04:33:20  aditya
  Stable version.

  Revision 1.2  2020/05/27 04:31:22  aditya
  Stable version.

  Revision 1.1  2020/05/27 04:13:30  aditya
  Initial commit.

------------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/libll.h"

typedef struct user 
{
  int key;
  int y;
  float z;
} usr;

ll *my_add(ll *pX, int key, int y, float z)
{
  usr *mydata = NULL;
  
  if ((mydata = (usr *)malloc(sizeof(usr))) == 0) {
    fprintf(stderr, "Unable to allocate memory. Fatal\n");
    exit(1);
  }

  mydata->key = key;
  mydata->y = y;
  mydata->z = z;

  pX = lladd(pX, mydata);

  return pX;
}

char *my_print(usr *this)
{
  static char s[80];
  sprintf(s, "key = %d, y = %d, z = %0.2f\n", this->key, this->y, this->z);
  return s;
}

int my_cmp(usr *mydata1, usr *mydata2)
{
  int a = 0;
  int b = 0;
  
  a = mydata1->y;
  b = mydata2->y;
  
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

int my_key_cmp(usr *mydata, int key)
{
  int a = 0;
  int b = 0;
  
  a = mydata->key;
  b = key;
  
  if (a == b)
    return 0;
  else
    return 1;
}

void my_free(usr *mydata)
{
  if (mydata) {
    free(mydata);
  }
}


int main(void)
{
  char *(*print)(usr*) = my_print;
  int (*cmp)(usr *, usr *) = my_cmp;
  int (*key_cmp)(usr *, int) = my_key_cmp;
  void (*free)(usr *mydata) = my_free;


  ll *pX = NULL;
  ll *sX = NULL;
  int i;
  

  pX = my_add(pX,  1, 123, 123.14);
  pX = my_add(pX,  2, 456,  24.15);
  pX = my_add(pX,  3, 510, 115.43);
  pX = my_add(pX,  4, 910,  15.43);
  pX = my_add(pX,  5, 130, 215.43);
  pX = my_add(pX,  6, 150, 125.43);
  pX = my_add(pX,  7, 105, 165.43);
  pX = my_add(pX,  8, 210, 154.73);
  pX = my_add(pX,  9, 101, 155.43);
  pX = my_add(pX, 10, 410, 145.43);
  pX = my_add(pX, 11, 180, 185.43);
  pX = my_add(pX, 12, 109, 158.43);


  llprint(pX, (char *(*)(void *))print);

  printf("\n");

  pX = llsort(pX, (int (*)(void *, void *))cmp);
  pX = lldelete(pX, 3, (int (*)(void *, int))key_cmp, (void (*)(void *))free);
  llprint(pX, (char *(*)(void *))print);

  sX = llsearch(pX, 12, (int (*)(void *, int))key_cmp);
  printf("\n");
  llprint_single(sX, (char *(*)(void *))print);

  i = llwhich(pX, 12, (int (*)(void *, int))key_cmp);
  printf("%d\n\n", i);

  lldestroy(pX, (void (*)(void *))free);
  llprint(pX, (char *(*)(void *))print);
  
  return 0;
}

