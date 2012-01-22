#ifndef _QNODE_H
#define _QNODE_H

#include "Queue.h"

class QNode {
 private:
  QItemType element;
  QNode *next;

 public:
  QNode(QItemType e, QNode *p=NULL);
  QItemType &getElement();
  QNode *getNext();
  void setElement(QItemType e);
  void setNext(QNode *p);
};

#endif
