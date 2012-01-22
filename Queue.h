/*
  Abstract Data Type for Queue
*/

#ifndef _QUEUE_H
#define _QUEUE_H

#include "OracleNode.h"

typedef OracleNode *QItemType;

class Queue {
 public:
  // Required default destructor.
  virtual ~Queue() {}

  // Return the number of elements in the queue.
  virtual int size() = 0;

  // Return true if the queue is empty, otherwise false.
  virtual bool isEmpty() = 0;

  // Return a reference to the item at the front of the queue.
  virtual QItemType &front() = 0;

  // Insert an item at the end of the queue.
  virtual void enqueue(QItemType item) = 0;

  // Remove and return the item at the front of the queue.
  virtual QItemType dequeue() = 0;
};


#endif
