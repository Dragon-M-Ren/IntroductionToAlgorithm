// Max Priority Queue
#pragma once
#include <utility>
#include <climits>
#include "06_s01_heap.h"
// Assume the min value of key is -1 for simplicity

template<class Data>
bool insert(heap<Data> &h, int key, Data data);

template<class Data>
std::pair<int, Data> maximum(heap<Data> &h);

template<class Data>
bool increase_key(heap<Data> &h, int index, int key);

template<class Data>
bool insert(heap<Data> &h, int key, Data data){
  // Check if the heap is full
  if(h.size == h.capacity) return false;
  
  // Insert to the last elment
  h.size++;
  h.key[h.size] = 0;
  h.data[h.size] = data; 

  increase_key(h, h.size, key);

  return true;
}

template<class Data>
std::pair<int, Data> maximum(heap<Data> &h){
  if(h.size == 0) return std::pair<int, Data>(-1, Data());
  
  return std::pair<int, Data>(h.key[1], h.data[1]);

}

template<class Data>
bool extract_max(heap<Data> &h){
  if(h.size == 0) return false;
  
  std::swap(h.key[1], h.key[h.size]);
  std::swap(h.data[1], h.data[h.size]);
  h.size--;
  Heapify(h, 1);

  return true;
}

template<class Data>
bool increase_key(heap<Data> &h, int index, int key){
  // Check
  if(h.size < index) return false;
  if(h.key[index] > key) return false;
  
  // Update and let it flow up
  Data tmp_data = h.data[index];
  int parent = PARENT(index);

  while(parent >= 1 && h.key[parent] < key){
    h.key[index] = h.key[parent];
    h.data[index] = h.data[parent];
    index = parent;
    parent = PARENT(index);
  }
  h.key[index] = key;
  h.data[index] = tmp_data;
  
  return true;
}

// delete any element from heap
/**
 * Strategy 
 * first increase it to the max value, then the element will be move to root
 * remove root
*/
template<class Data>
bool heap_delete(heap<Data> &h, int index){
  // Element doesn't exist
  if(index > h.size) return false;
  
  increase_key(h, index, INT32_MAX);
  extract_max(h);

  return true;
}