#include "06_s01_heap.h"

template<class Data>
void HeapSort(heap<Data> &h){
  BuildHeap(h);

  for(int end = h.size; end > 1; end--){
    std::swap(h.key[1], h.key[end]);
    std::swap(h.data[1], h.data[end]);
    h.size--;
    Heapify(h, 1);
  }
}