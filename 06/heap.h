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

// Note: using shouldn't be used in hearder files
// Since this is only for test and then this usage is okay


struct Empty{
};

// The Data used by heap
template <class Data>
class Element{
private:
  int key_;
  Data data_;
public:
  Element(int key, Data data): key_(key), data_(data){}
  int GetKey() const{return key_;}
  Data GetData() const{return data_;}
};

template<>
class Element<Empty>{
private:
  int key_;
public:
  Element(int key): key_(key){}
  int GetKey() const {return key_;}
  void GetData() const {return;} 
};

// Help functions of building Element vector
template<class Data>
std::vector<Element<Data> > BuildElementVector(std::vector<int> keys, std::vector<Data> data);

std::vector<Element<Empty> > BuildElementVector(std::vector<int> keys);

// The heap class
template <class Data>
class Heap{
private:
  // Use vector for simplicity, the actural index starts from 1
  std::vector<Element<Data> > data_;
  int size_;
public:
  Heap();
  Heap(std::vector<Element<Data> > arr);
  void Insert(Element<Data> e);
  bool Pop();
  Element<Data> Top();
  
  bool Exist();
  
  // This implementation seems ugly
  // The state in argument is used to return if the return is available
  // Seems useless
  Element<Data>& ParentElement(int i, bool &state);
  Element<Data>& LeftElement(int i, bool &state);
  Element<Data>& RightElement(int i, bool &state);
  
  
  // The version that will just return the index
  int Parent(int i) {return i/2;}
  int Left(int i) {return i*2;}
  int Right(int i) {return i*2+1;}
  
  // Create a heap from the original array
  void Heapify(int index);
  void HeapifyNonRecursive(int index);

  // Heapsort
  void Sort();

  // Print the array
  void Show();
  void ShowAll();
  void ShowKeyAsTree();

  void BuildHeap();
};

template<class Data>
Heap<Data>::Heap(){
;
}

template<class Data>
Heap<Data>::Heap(std::vector<Element<Data> > arr): size_(arr.size()){
  // If the vector is empty, use the default constructor
  if(size_ == 0){
    Heap();
    return;
  }
  std::cout << size_ << std::endl;
  // The first element is not used, although it can be used to 
  // store the size of the heap
  auto first_element = arr[0];
  arr.push_back(first_element);
  data_ = arr;
  
  BuildHeap();
}

template<class Data>
void Heap<Data>::Heapify(int index){
  int left = Left(index);
  int right = Right(index);
  int largest = index;

  if(left <= size_ && data_[left].GetKey() GT data_[largest].GetKey())
    largest = left;
  
  if(right <= size_ && data_[right].GetKey() GT data_[largest].GetKey())
    largest = right;
  
  // If the largest element isn't the root of the subtree
  if(largest != index){
    std::swap(data_[index], data_[largest]);
    Heapify(largest);
  }
}

template<class Data>
void Heap<Data>::HeapifyNonRecursive(int index){
  int left = Left(index);
  int right = Right(index);
  int parent = index;
  int largest = index;
  
  // first round
  if(left <= size_ && data_[left].GetKey() GT data_[parent].GetKey())
    parent = left;
  if(right <= size_ && data_[right].GetKey() GT data_[parent].GetKey())
    parent = right;
  

  while(parent != largest){
    // If the parent element isn't the root of the subtree
    std::swap(data_[largest], data_[parent]);
    parent = largest;
    left = Left(parent);
    right = Right(parent);
    
    if(left <= size_ && data_[left].GetKey() GT data_[parent].GetKey())
      parent = left;
    if(right <= size_ && data_[right].GetKey() GT data_[parent].GetKey())
      parent = right;
  }
}

template<class Data>
Element<Data>& Heap<Data>::ParentElement(int i, bool &state){
  int index = Parent(i);
  if(i < data_.size()){
    state = true;
    return data_[index];
  }
  state = false;
  return data_[0];
}

template<class Data>
Element<Data>& Heap<Data>::LeftElement(int i, bool &state){
  int index = Left(i);
  if(i < data_.size()){
    state = true;
    return data_[index];
  }
  state = false;
  return data_[0];
}

template<class Data>
Element<Data>& Heap<Data>::RightElement(int i, bool &state){
  int index = Right(i);
  if(i < data_.size()){
    state = true;
    return data_[index];
  }
  state = false;
  return data_[0];
}

template<class Data>
void Heap<Data>::Sort(){
  for(int i = size_; i > 1; i--){
    std::swap(data_[1], data_[i]);
    size_--;
    Heapify(1);
  }
}

template<class Data>
void Heap<Data>::Show(){
  std::vector<int> keys;

  for(int i = 1; i <= size_; i++){
    keys.push_back(data_[i].GetKey());
  }

  print_int_vector(keys);
}

template<class Data>
void Heap<Data>::ShowAll(){
  std::vector<int> keys;
  for(int i = 1; i < data_.size(); i++){
    keys.push_back(data_[i].GetKey());
  }

  print_int_vector(keys);
}

template<class Data>
void Heap<Data>::ShowKeyAsTree(){
  // The root has depth 1
  //int total_level = ceil(log2(N + 1));

  // int cur_print_offset = ;
  // int cur_interval = ;
  int cur_offset = 1;
  int cur_element_num = 1;

}

template<class Data>
void Heap<Data>::BuildHeap(){
  for(int i = size_/2; i > 0; i--)
    Heapify(i);
}


// Implementations for help functions
template<class Data>
std::vector<Element<Data> > BuildElementVector(std::vector<int> keys, std::vector<Data> data){
  std::vector<Element<Data> > ret;

  if(keys.size() != data.size()){
    std::cout << "The size doesn't match\n";
    return ret;
  }

  for(int i = 0; i < keys.size(); i++){
    ret.push_back(Element<Data>(keys[i], data[i]));
  }

  return ret;
}

std::vector<Element<Empty> > BuildElementVector(std::vector<int> keys){
  std::vector<Element<Empty> > ret;

  for(int i = 0; i < keys.size(); i++){
    ret.push_back(Element<Empty>(keys[i]));
  }
  std::cout << "Input key size: " << keys.size() << std::endl;
  std::cout << "Input vector size: " << ret.size() << std:: endl;

  return ret;
}