/*------------------------------------------------------------------------------
  (C) Aditya V. Nebhrajani 2020
  File: libll.c 
  Description: Generic linked list library.

---------------------------------RCS/CVS----------------------------------------
  $Id: libll.c,v 1.8 2020/05/31 13:37:02 aditya Exp $
  $Author: aditya $
  $Source: /auto/common/.cvsroot/libll/src/libll.c,v $
  $Revision: 1.8 $
  $Date: 2020/05/31 13:37:02 $
  $Log: libll.c,v $
  Revision 1.8  2020/05/31 13:37:02  aditya
  Final version.

  Revision 1.7  2020/05/30 16:18:39  aditya
  Latest stable version.

  Revision 1.6  2020/05/27 04:52:09  aditya
  Final release.

  Revision 1.5  2020/05/27 04:29:43  aditya
  Sort and append functions added: not working.

  Revision 1.4  2020/05/25 09:31:28  aditya
  Formatting fix.

  Revision 1.3  2020/05/25 09:30:37  aditya
  Formatting edit.

  Revision 1.2  2020/05/25 09:09:39  vijayn
  Minor format modifications.

  Revision 1.1  2020/05/25 09:23:03  aditya
  Initial commit.

------------------------------------------------------------------------------*/

#include "libll.h"

/*------------------------------------------------------------------------------
  Function Name: _llcreate
  Description:   (Internal) creates a new linked list.
------------------------------------------------------------------------------*/
ll *_llcreate(void)
{
  ll *pll;

  if ((pll = malloc(sizeof(struct llnode))) == 0) {
    fprintf(stderr, "Unable to allocate memory. Fatal\n");
    exit(1);
  }
  
  pll->_next = 0;
  return pll;
}

/*------------------------------------------------------------------------------
  Function Name: lladd
  Description:   Adds an element to a list. If list doesn't exist, creates anew.
------------------------------------------------------------------------------*/
ll *lladd(ll *_list, void *_data) 
{
  ll *newlst = 0;
  
  if (!_list) {
    newlst = _llcreate();
    newlst->_data = _data;
    return newlst;
  }
  else if (_list->_next) {
    lladd(_list->_next, _data);
    return _list;
  }
  else {
    _list->_next = _llcreate();
    _list->_next->_data = _data;
    return _list; 
  }
}

/*------------------------------------------------------------------------------
  Function Name: (Internal) _lldelete
  Description:   Deletes element from list.
------------------------------------------------------------------------------*/
ll *_lldelete(ll *_list, void *_data)
{
  
  ll *_this = 0;
  ll *_prev = 0;
  ll *_tmp = 0;

  for (_this = _list; _this; _this = _this->_next) {
    if (_this->_data == _data) {
      if (!_prev) { // _This is the first element.
        _tmp = _this->_next;
        free(_this);
        return _tmp;
      }
      else if (_this->_next == 0) { // _This is the last element
        _prev->_next = 0;
        free(_this);
        return _list;
      }
      else { // All other elements.
        _prev->_next = _this->_next;
        free(_this);
        return _list;
      }
    }
    _prev = _this;
  }
  return _list;
}

/*------------------------------------------------------------------------------
  Function Name: llsearch
  Description:   Searches element in list.
------------------------------------------------------------------------------*/
ll *llsearch(ll *_list, int _key, int (* usr_compare_key)(void *_data, int key))
{
  if (_list) {
    if (usr_compare_key(_list->_data, _key) == 0) {
      return _list;
    }
    else {
      return llsearch(_list->_next, _key, usr_compare_key);
    }
  }
  return NULL;
}

/*------------------------------------------------------------------------------
  Function Name: llprint
  Description:   Prints list.
------------------------------------------------------------------------------*/
void llprint(ll *_list, char *(* usr_print)(void *_data)) 
{
  ll *_this;
  
  for (_this = _list; _this; _this = _this->_next) {
    printf("%s", usr_print(_this->_data));
  }
}

/*------------------------------------------------------------------------------
  Function Name: llappend
  Description:   Appends to non-null list.
------------------------------------------------------------------------------*/
ll *llappend(ll *_a, ll *_b)
{
  ll *_this;
  
  if (!_a && !_b) {
    return NULL;
  }

  if (!_a) {
    return _b;
  }
  else {
    for (_this = _a; _this->_next; _this = _this->_next);
    _this->_next = _b;
    return _a;
  }
}

/*------------------------------------------------------------------------------
  Function Name: llsort
  Description:   Sorts list based on input compare function.
------------------------------------------------------------------------------*/
ll *llsort(ll *_list, int (* usr_compare)(void *_data1, void *_data2))
{
  ll *_left = _list, *_right = NULL;
  ll *_this = NULL;
  ll *_cmp = NULL;
  ll *_pivot = NULL;
  
  if (!_list) {
    return NULL;
  }

  if (_list->_next == 0) {
    return _list;
  }
  else {

    _cmp = _list->_data;

    for (_this = _list; _this; _this = _this->_next) {
      if (usr_compare(_this->_data, _cmp) == 0) {
        _pivot = lladd(_pivot, _this->_data);
        _left = _lldelete(_left, _this->_data);
      }
      else if (usr_compare(_this->_data, _cmp) > 0) {
        _right = lladd(_right, _this->_data);
        _left = _lldelete(_left, _this->_data);
      }
    }
    
    return llappend(llsort(_left, usr_compare), llappend(_pivot, llsort(_right, usr_compare)));
    
  }
}

/*------------------------------------------------------------------------------
  Function Name: llprint_single
  Description:   Prints specified element of list.
------------------------------------------------------------------------------*/
void llprint_single(ll *_this, char *(* usr_print)(void *_data)) 
{
    printf("%s", usr_print(_this->_data));
}


/*------------------------------------------------------------------------------
  Function Name: lldelete
  Description:   Deletes element from list.
------------------------------------------------------------------------------*/
ll *lldelete(ll *_list, int _key, int (* usr_compare_key)(void *_data, int key), void (* usr_free)(void *_data)) 
{
 
  ll *_this = 0;
  ll *_prev = 0;
  ll *_tmp = 0;

  for (_this = _list; _this; _this = _this->_next) {
    if (usr_compare_key(_this->_data, _key) == 0) {
      if (!_prev) { // _This is the first element.
        _tmp = _this->_next;
        usr_free(_this->_data);
        free(_this);
        return _tmp;
      }
      else if (_this->_next == 0) { // _This is the last element
        _prev->_next = 0;
        usr_free(_this->_data);
        free(_this);
        return _list;
      }
      else { // All other elements.
        _prev->_next = _this->_next;
        usr_free(_this->_data);
        free(_this);
        return _list;
      }
    }
    _prev = _this;
  }
  return _list;
}

/*------------------------------------------------------------------------------
  Function Name: llwhich
  Description:   Whichth node is element at?
------------------------------------------------------------------------------*/
int llwhich(ll *_list, int _key, int (* usr_compare_key)(void *_data, int key)) 
{
  ll *_this = 0;
  int _i = 0;
  
  for (_this = _list; _this; _this = _this->_next) {
    if (usr_compare_key(_this->_data, _key) == 0) {
      return _i;
    }
    _i++; 
  }
  return -1;
}

/*------------------------------------------------------------------------------
  Function Name: lldestroy
  Description:   Destroy whole list.
------------------------------------------------------------------------------*/
void lldestroy(ll *_list, void (* usr_free)(void *_data))
{
  ll *_this = 0;

 for (_this = _list; _this; _this = _this->_next) {
   usr_free(_this->_data);
   free(_this);
 }
}

/* -------------------------------------------------------------------------------- */
/* <EOF> */
/* -------------------------------------------------------------------------------- */
