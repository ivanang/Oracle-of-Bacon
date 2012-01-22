/*
  Abstract Data Type for List
*/

#ifndef _LIST_H
#define _LIST_H

#include <string>
using std::string;

typedef string ListItemType;

class List {
 public:
  virtual ~List() {}
  virtual int length() = 0;
  virtual ListItemType get(int index) = 0;
  virtual void append(ListItemType item) = 0;
  virtual void insert(int index, ListItemType item) = 0;
  virtual ListItemType pop(int index) = 0;
  virtual void set(int index, ListItemType item) = 0;
};

#endif
