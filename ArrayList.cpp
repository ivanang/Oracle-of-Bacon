#include <iostream>
#include <stdexcept>
#include "ArrayList.h"

using namespace std;

void ArrayList::doubleCapacity() {
  capacity *= 2;
  ListItemType *bigger = new ListItemType[capacity];
  for (int i=0; i<size; i++)
    bigger[i] = array[i];
  delete [] array;
  array = bigger;
}

ArrayList::ArrayList(int initCap) {
  capacity = initCap;
  size = 0;
  array = new ListItemType[capacity];
}

ArrayList::~ArrayList() {
  delete [] array;
}

int ArrayList::length() {
  return size;
}

ListItemType ArrayList::get(int index) {
  if (index >= size || index < 0)
    throw runtime_error("get called with index out of range");
  return array[index];
}

void ArrayList::append(ListItemType item) {
  if (size == capacity) 
    doubleCapacity();
  array[size++] = item;
}

void ArrayList::insert(int index, ListItemType item) {
  if (index >= size || index < 0)
    throw runtime_error("insert called with index out of range");
  if (size == capacity)
    doubleCapacity();
  for (int i=size; i>index; i--) 
    array[i] = array[i-1];
  array[index] = item;
  size++;
}

ListItemType ArrayList::pop(int index) {
  if (index >= size || index < 0)
    throw runtime_error("pop called with index out of range");
  ListItemType result = array[index];
  for (int i=index; i<size-1; i++) 
    array[i] = array[i+1];
  size--;
  return result;
}

void ArrayList::set(int index, ListItemType item) {
  if (index >= size || index < 0) 
    throw runtime_error("set called with index out of range");
  array[index] = item;
}
    
