#include <iostream>
#include "QNode.h"

using namespace std;

QNode::QNode(QItemType e, QNode *p) {
  element = e;
  next = p;
}

QItemType &QNode::getElement() {
  return element;
}

QNode *QNode::getNext() {
  return next;
}

void QNode::setElement(QItemType e) {
  element = e;
}

void QNode::setNext(QNode *p) {
  next = p;
}

