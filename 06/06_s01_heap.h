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

// Separate hey and data for simplicity
template<class Data>
struct heap{
  int *key;
  Data *data;
  int size;
  int capacity;
  
  heap(int c){
    key = new int[c+1];
    data = new Data[c+1];
    size = 0;
    capacity = c;
  }
};

struct Empty{
};

// Data is the type of data in Element
template<class Data>
void Heapify(heap<Data> &h, int node){
//void Heapify(Element<Data> *data, int node, int heap_size){
  int left = LEFT(node);
  int right = RIGHT(node);
  int max = node;

  if(left <= h.size && h.key[left] GT h.key[max])
    max = left;

  if(right <= h.size && h.key[right] GT h.key[max])
    max = right;
  
  if(max == node)
    return;
  
  // Exchange and call recursively
  std::swap(h.data[node], h.data[max]);
  std::swap(h.key[node], h.key[max]);
  Heapify(h, max);
}

template<class Data>
void HeapifyNonRecur(heap<Data> &h, int node){
//void HeapifyNonRecur(Element<Data> *data, int node, int heap_size){
  int left, right;
  int max = node; // Unavaliable 
  int parent = node;

  while(1){
    left = LEFT(parent);
    right = RIGHT(parent);

    // check max
    if(left <= h.size && h.key[left] GT h.key[max])
      max = left;
    if(right <= h.size && h.key[right] GT h.key[max])
      max = right;

    if(max == parent)
      break;

    std::swap(h.data[parent], h.data[max]);
    std::swap(h.key[parent], h.key[max]);
    parent = max;
  }
}

template<class Data>
void BuildHeap(heap<Data> &h){
//void BuildHeap(Element<Data> *data, int heap_size){
  for(int node = h.size/2; node > 0; node--)
    Heapify(h, node);
}


template<class Data>
void BuildHeapNonRecur(heap<Data> &h){
//void BuildHeapNonRecur(Element<Data> *data, int heap_size){
  for(int node = h.size/2; node > 0; node--)
    HeapifyNonRecur(h, node);
}

template<class Data>
bool TestHeap(heap<Data> &h, const int node){
//bool TestHeap(Element<Data> *data, const int node, const int heap_size){
  int left = LEFT(node);
  int right = RIGHT(node);

  bool left_statisfied = true;
  bool right_statisfied = true;

  if(left <= h.size){
    if(h.key[left] GT h.key[node]){
      std::cout << "Heap test failed at \n";
      std::cout << "Parent: index " << node << " value " <<  h.key[node] << std::endl;
      std::cout << "Node left: index " << left << " value " << h.key[left] << std::endl;
      return false;
     }
    else{
      if(!TestHeap(h, left))
        return false;
    }    
  }  
    
  if(right <= h.size){
    if(h.key[right] GT h.key[node]){
      std::cout << "Heap test failed at \n";
      std::cout << "Parent: index " << node << " value " <<  h.key[node] << std::endl;
      std::cout << "Node right: index " << right << " value " << h.key[right] << std::endl;
      return false;
    }
    else{
      if(!TestHeap(h, right))
        return false;
    }   
  }
  return true;
}

template<class Data>
bool TestHeapInteface(heap<Data> &h){
//bool TestHeapInteface(Element<Data> *data, const int heap_size){
  return TestHeap<Data>(h, 1);
}

// Helper function to create Eelement with only key

// Assume length > 0 and the buffer has enough space
template<class Data>
void BuildElementVector(heap<Data> &h, int * keys, Data * data, const int length){
  if(length > h.capacity){
    std::cout << "Not enough capacity in heap\n";
    exit(1);
  }

  for(int i = 0; i < length; i++){
    h.key[i+1] = keys[i];
    h.data[i+1] = data[i];
  }
  h.size = length;
}

template<class Data>
void BuildElementVector(heap<Empty> &h, int *keys, const int length){
  if(length > h.capacity){
    std::cout << "Not enough capacity in heap\n";
    exit(1);
  }

  for(int i = 0; i < length; i++)
    h.key[i+1] = keys[i];
   
  h.size = length;
}

template<class Data>
void PrintHeapKeys(heap<Data> &h){
  print_int_array(h.key+1, h.size);
}