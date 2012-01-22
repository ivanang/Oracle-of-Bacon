#ifndef _LINKEDQUEUE_H
#define _LINKEDQUEUE_H

#include <cstdlib> 
#include "Queue.h"
#include "QNode.h"

class LinkedQueue : public Queue {
 private:
  QNode *f;
  QNode *b;
  int n;

 public:
  ~LinkedQueue();
  LinkedQueue();
  int size();
  bool isEmpty();
  QItemType &front();
  void enqueue(QItemType item);
  QItemType dequeue();
};

#endif
