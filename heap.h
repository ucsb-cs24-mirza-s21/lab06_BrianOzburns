// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza
// Brian Ozawa Burns, 05/28/2021

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:
    void push(int value);     // insert value; //duplicates are allowed
    void pop(); // delete the min element 
    int top();
    bool empty();
    void print() const;
    
 private:
    std::vector<int> vdata; //store the binary heap tree as a dynamic array
};

#endif