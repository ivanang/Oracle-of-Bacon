#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include "List.h"

class ArrayList : public List {
 private:
  ListItemType *array;
  int capacity;
  int size;
  void doubleCapacity();

 public:
  ArrayList(int initCap=100);
  ~ArrayList();
  int length();
  ListItemType get(int index);
  void append(ListItemType item);
  void insert(int index, ListItemType item);
  ListItemType pop(int index);
  void set(int index, ListItemType item);
};

#endif
