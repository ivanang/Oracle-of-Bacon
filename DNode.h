#ifndef _DNODE_H
#define _DNODE_H

#include <string>
#include "ArrayList.h"
using std::string;

typedef string DKeyType;
typedef ArrayList *DItemType;

class DNode {
 private:
  DKeyType key;
  DItemType element;
  
 public:
  DNode(DKeyType k, DItemType e);
  DKeyType getKey();
  DItemType getElement();
  void setKey(DKeyType k);
  void setElement(DItemType e);
};

#endif
