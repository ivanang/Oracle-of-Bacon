#include "DNode.h"

DNode::DNode(DKeyType k, DItemType e) {
  key = k;
  element = e;
}

DKeyType DNode::getKey() {
  return key;
}

DItemType DNode::getElement() {
  return element;
}

void DNode::setKey(DKeyType k) {
  key = k;
}

void DNode::setElement(DItemType e) {
  element = e;
}
