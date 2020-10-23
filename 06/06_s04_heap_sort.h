#include "06_s01_heap.h"

template<class Data>
void HeapSort(Element<Data> *data, int length){
  BuildHeap(data, length);

  int end = length;
  
  for(int end = length; end > 1; end--){
    std::swap(data[1], data[end]);
    Heapify(data, 1, end - 1);
  }
}