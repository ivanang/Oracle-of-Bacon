/*
   Abstract data type for Dictionary. All keys are unique.  
*/

#ifndef _DICTIONARY_H
#define _DICTIONARY_H

#include <vector>
#include "DNode.h"

using std::vector;

class Dictionary {
 public:
  ~Dictionary() {}
  // return the element associated with the given key, error if not found
  virtual DItemType get(DKeyType key)=0;

  // if the key is new, insert the key and the associated element
  // otherwise, update the element
  virtual void put(DKeyType key, DItemType element)=0;

  // return and remove the element associated with the given key
  virtual DItemType remove(DKeyType key)=0;

  // return the size of the dictionary
  virtual int size()=0;

  // return whether the dictionary is empty
  virtual bool isEmpty()=0;

  // return whether the dictionary contains the given key
  virtual bool containsKey(DKeyType key)=0;

  // return whether the dictionary contains the given element
  virtual bool containsElement(DItemType element)=0;

  // return a vector containing all the keys in the dictionary
  virtual vector<DKeyType> keys()=0;

  // return a vector containing all the elements in the dictionary
  virtual vector<DItemType> elements()=0;
};

#endif
