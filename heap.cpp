// heap.cpp
// Diba Mirza
// Brian Ozawa Burns, 05/28/2021

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  if (vdata.empty()){
    return;
  }

  // Percolate up
  int intIndex = vdata.size()-1;

  while (intIndex > 0){
    int parentIndex = (intIndex-1)/2;
    if (vdata[intIndex] >= vdata[parentIndex]){
      return;
    }
    else {
      int temp = vdata[intIndex];
      vdata[intIndex] = vdata[parentIndex];
      vdata[parentIndex] = temp;

      intIndex = parentIndex;
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.empty()){
    cout << "popping from empty heap\n";
    return;
  }

  // Percolate down
  vdata[0] = vdata[vdata.size()-1];
  vdata.resize(vdata.size() - 1);
  int intIndex = 0;
  int childIndex = 2*intIndex + 1;
  int value = vdata[intIndex];

  while (childIndex < vdata.size()){
    int minVal = value;
    int minIndex = -1;
    int i = 0;
    while (i<2 && i+childIndex < vdata.size()){
      if (vdata[i+childIndex] < minVal){
        minVal = vdata[i+childIndex];
        minIndex = i+childIndex;
      }
      i++;
    }
    if (minVal == value){
      return;
    }
    else {
      int temp = vdata[intIndex];
      vdata[intIndex] = vdata[minIndex];
      vdata[minIndex] = temp;
      intIndex = minIndex;
      childIndex = 2*intIndex + 1;
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.empty()){
    return 0;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}

// prints all elements
void Heap::print() const{
  for (int i = 0; i < vdata.size(); i++){
    cout << vdata[i] << "\n";
  }
}
    