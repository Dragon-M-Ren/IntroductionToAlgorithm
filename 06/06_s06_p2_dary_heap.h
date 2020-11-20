#pragma once

#include <utility>
#include "../util/print.h"
// Data is omitted, only store int keys
// The minimum key is 0 (for convenience)
// The root is 1
struct dary_heap{
  int d;
  int capacity;

  int *keys;
  int size;
  
  dary_heap(int d_, int c): d(d_), capacity(c), size(0){
    keys = new int[capacity+1];
  }
  /*
  ~dary_heap(){
    delete [] keys;
  }*/
};
void print_dary_heap(dary_heap &dh);

inline int parent(dary_heap &dh, int node){
  return (node+1)/dh.d;
}

// offset starts from 1
inline int child(dary_heap &dh, int node, int offset){
  return node * dh.d - dh.d + 1 + offset;
}

// Only provide the recursive method for simplicity
void dheapify(dary_heap &dh, int node){
  int max = node;
  
  // Check all the childs
  for(int each_child = child(dh, node, 1); 
          each_child <= child(dh, node, dh.d) && each_child <= dh.size; each_child++){
    if(dh.keys[max] < dh.keys[each_child])
      max = each_child;
  }
  
  // Switch with the largest child and call recursively 
  if(node != max){
    std::swap(dh.keys[max], dh.keys[node]);
    dheapify(dh, max);
  }
}

int extract_max(dary_heap &dh){
  // the heap is empty
  if(dh.size < 1) return -1;
  int ret = dh.keys[1];
  
  dh.keys[1] = dh.keys[dh.size];
  dh.size--;
  
  dheapify(dh, 1);

  return ret;
}

void increase_key(dary_heap &dh, int node, int new_key){
  if(dh.size < node) return;
  if(dh.keys[node] >= new_key) return;
  
  int p = parent(dh, node);
  while(p > 0 && dh.keys[p] < new_key){
    dh.keys[node] = dh.keys[p];
    node = p;
    p = parent(dh, node);
  }
  
  dh.keys[node] = new_key;
}

void insert(dary_heap &dh, int key){
  // the heap is full
  if(dh.size == dh.capacity) return;
  dh.size++;
  dh.keys[dh.size] = 0;
  
  increase_key(dh, dh.size, key);
}

bool is_dary_heap(dary_heap &dh){
  for(int i = 1; i <= (dh.size + dh.d - 2)/dh.d; i++){
    for(int c = child(dh, i, 1); c <= dh.size && c <= child(dh, i, dh.d); c++){
      if(dh.keys[i] < dh.keys[c]) return false;
    }
  }
  return true;
}

void build_dary_heap(dary_heap &dh, int* keys, int len){
  for(int i = 0; i < len; i++)
    insert(dh, keys[i]);
}

void print_dary_heap(dary_heap &dh){
  print_int_array(dh.keys+1, dh.size);
}