#ifndef _HASHTABLEDICTIONARY_H
#define _HASHTABLEDICTIONARY_H

#include <vector>
#include "DNode.h"
#include "Dictionary.h"

using std::vector;

class HashTableDictionary : public Dictionary {
 private:
  // an array of vectors holding DNode pointers
  vector<DNode *> *table;
  int n;
  int capacity;
  DNode *findNode(DKeyType key);

 public:
  HashTableDictionary(int cap=53);  //capacity should be prime
  DItemType get(DKeyType key);
  void put(DKeyType key, DItemType element);
  DItemType remove(DKeyType key);
  int size();
  bool isEmpty();
  bool containsKey(DKeyType key);
  bool containsElement(DItemType element);    
  vector<DKeyType> keys();
  vector<DItemType> elements();
  int hashCode(int key);
  int hashCode(string key);
  void display();
};

#endif
