#include <iostream>
#include <stdexcept>
#include "LinkedQueue.h"

using namespace std;

LinkedQueue::LinkedQueue() {
  f = NULL;
  b = NULL;
  n = 0;
}

LinkedQueue::~LinkedQueue() {
  QNode *previous, *current;
  previous = NULL;
  current = f;
  while (current != NULL) {
    previous = current;
    current = current->getNext();
    delete previous;
  }
}

int LinkedQueue::size() {
  return n;
}

bool LinkedQueue::isEmpty() {
  return n == 0;
}

QItemType &LinkedQueue::front() {
  if (isEmpty())
    throw runtime_error("front called on an empty queue");
  return f->getElement();
}

void LinkedQueue::enqueue(QItemType item) {
  QNode *added = new QNode(item);
  if (isEmpty())
    f = added;
  else
    b->setNext(added);
  b = added;
  n += 1;
}

QItemType LinkedQueue::dequeue() {
  if (isEmpty())
    throw runtime_error("dequeue called on an empty queue");
  QNode *old = f;
  QItemType result = f->getElement();
  f = f->getNext();
  n -= 1;
  if (n == 0)
    b = NULL;
  delete old;
  return result;
}
