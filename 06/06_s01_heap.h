#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>

#include "../util/print.h"
// Define the comparision operator
#ifndef MIN
#define GT > // larger than
#else
#define GT <
#endif 

#define PARENT(x) x >> 1
#define LEFT(x) x << 1
// Note + has higher precedence
#define RIGHT(x) (x << 1) + 1

// Note: using shouldn't be used in hearder files
// Since this is only for test and then this usage is okay

struct Empty{
};

// The Data used by heap
// The assignment operator should works for Data, or the heap won't work
template <class Data>
class Element{
private:
  int key_;
  Data data_;
public:
  Element(): key_(0){};
  Element(int key): key_(key){} // whent the real data doesn't matter
  Element(int key, Data data): key_(key), data_(data){}
  int GetKey() const{return key_;}
  Data GetData() const{return data_;}
};

// Data is the type of data in Element
template<class Data>
void Heapify(Element<Data> *data, int node, int heap_size){
  int left = LEFT(node);
  int right = RIGHT(node);
  int max = node;

  if(left <= heap_size && data[left].GetKey() GT data[max].GetKey())
    max = left;

  if(right <= heap_size && data[right].GetKey() GT data[max].GetKey())
    max = right;
  
  if(max == node)
    return;
  
  // Exchange and call recursively
  std::swap(data[node], data[max]);
  Heapify(data, max, heap_size);
}

template<class Data>
void HeapifyNonRecur(Element<Data> *data, int node, int heap_size){
  int left, right;
  int max = node; // Unavaliable 
  int parent = node;

  while(1){
    left = LEFT(parent);
    right = RIGHT(parent);

    // check max
    if(left <= heap_size && data[left].GetKey() GT data[max].GetKey())
      max = left;
    if(right <= heap_size && data[right].GetKey() GT data[max].GetKey())
      max = right;

    if(max == parent)
      break;

    std::swap(data[max], data[parent]);
    parent = max;
  }
}

template<class Data>
void BuildHeap(Element<Data> *data, int heap_size){
  for(int node = heap_size/2; node > 0; node--)
    Heapify(data, node, heap_size);
}


template<class Data>
void BuildHeapNonRecur(Element<Data> *data, int heap_size){
  for(int node = heap_size/2; node > 0; node--)
    HeapifyNonRecur(data, node, heap_size);
}

template<class Data>
bool TestHeap(Element<Data> *data, const int node, const int heap_size){
  int left = LEFT(node);
  int right = RIGHT(node);

  bool left_statisfied = true;
  bool right_statisfied = true;

  if(left <= heap_size){
    if(data[left].GetKey() GT data[node].GetKey()){
      std::cout << "Heap test failed at \n";
      std::cout << "Parent: index " << node << " value " <<  data[node].GetKey() << std::endl;
      std::cout << "Node left: index " << left << " value " << data[left].GetKey() << std::endl;
      return false;
     }
    else{
      if(!TestHeap(data, left, heap_size))
        return false;
    }    
  }  
    
  if(right <= heap_size){
    if(data[right].GetKey() GT data[node].GetKey()){
      std::cout << "Heap test failed at \n";
      std::cout << "Parent: index " << node << " value " <<  data[node].GetKey() << std::endl;
      std::cout << "Node right: index " << right << " value " << data[right].GetKey() << std::endl;
      return false;
    }
    else{
      if(!TestHeap(data, right, heap_size))
        return false;
    }   
  }
  return true;
}

template<class Data>
bool TestHeapInteface(Element<Data> *data, const int heap_size){
  return TestHeap(data, 1, heap_size);
}

// Helper function to create Eelement with only key

// Assume length > 0 and the buffer has enough space
template<class Data>
void BuildElementVector(int * keys, Data * data, Element<Data> result, const int length){
  for(int i = 0; i < length; i++){
    result[i+1] = Element<Data>(keys[i], data[i]);
  }
}

template<class Data>
void BuildElementVector(int *keys, Element<Empty> *result, const int length){

  for(int i = 0; i < length; i++){
    result[i+1] = Element<Empty>(keys[i]);
  }
  //std::cout << "Input key size: " << keys.size() << std::endl;
  //std::cout << "Input vector size: " << ret.size() << std:: endl;
}

template<class Data>
void PrintHeapKeys(Element<Data> *data, const int length){
  for(int i = 1; i < length + 1; i++){
    std::cout << data[i].GetKey() << " ";
  }

  std::cout << std::endl;
}