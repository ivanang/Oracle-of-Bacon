#include <stdexcept>
#include <iostream>
#include <vector>
#include "HashTableDictionary.h"

using namespace std;

HashTableDictionary::HashTableDictionary(int cap) {
  // hash table is an array of vectors holding DNode pointers
  table = new vector<DNode *>[cap];
  n = 0;
  capacity = cap;
}

DNode *HashTableDictionary::findNode(DKeyType key) {
  int i = hashCode(key);
  for (int j=0; j<table[i].size(); j++) {
    if (table[i][j]->getKey() == key)
      return table[i][j];
  }
  return NULL;
}

DItemType HashTableDictionary::get(DKeyType key) {
  DNode *result = findNode(key);
  if (result != NULL)
    return result->getElement();
  else
    throw runtime_error("key not found in dictionary");
}

void HashTableDictionary::put(DKeyType key, DItemType element) {
  DNode *result = findNode(key);
  if (result != NULL) {
    result->setElement(element);
  }
  else {
    table[hashCode(key)].push_back(new DNode(key, element));
    n++;
  }
}

DItemType HashTableDictionary::remove(DKeyType key) {
  int i = hashCode(key);
  int position = -1;
  for (int j=0; j<table[i].size(); j++) {
    if (table[i][j]->getKey() == key) {
      position = j;
      break;
    }
  }
  if (position == -1)
    throw runtime_error("cannot remove key");
  table[i].erase(table[i].begin()+position-1);
  n--;
}

int HashTableDictionary::size() {
  return n;
}

bool HashTableDictionary::isEmpty() {
  return n == 0;
}

bool HashTableDictionary::containsKey(DKeyType key) {
  return findNode(key) != NULL;
}

bool HashTableDictionary::containsElement(DItemType element) {
  vector<DItemType> v = elements();
  for (int i=0; i<v.size(); i++) 
    if (v[i] == element)
      return true;
  return false;
}

vector<DKeyType> HashTableDictionary::keys() {
  vector<DKeyType> v;
  for (int i=0; i<capacity; i++) {
    for (int j=0; j<table[i].size(); j++) {
      v.push_back(table[i][j]->getKey());
    }
  }
  return v;
}

vector<DItemType> HashTableDictionary::elements() {
  vector<DItemType> v;
  for (int i=0; i<capacity; i++) {
    for (int j=0; j<table[i].size(); j++) {
      v.push_back(table[i][j]->getElement());
    }
  }
  return v;
}

int HashTableDictionary::hashCode(int key) {
  return key % capacity;
}

int HashTableDictionary::hashCode(string key) {
  int total=0;
  for (int i=0; i<key.size(); i++) {
    total += (int)key[i];
  }
  return total % capacity;
}

void HashTableDictionary::display() {
  printf("\nDictionary contains\n");
  for (int i=0; i<capacity; i++) {
    printf("%3d| ", i);
    for (int j=0; j<table[i].size(); j++)
      cout << table[i][j]->getKey() << ":" << table[i][j]->getElement() << " ";
    printf("\n");
  }
}
