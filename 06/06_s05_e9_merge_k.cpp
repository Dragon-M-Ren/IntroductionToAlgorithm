// Use a min-heap for sorting
// Note there are some collision in the priority queue part
// Don't use increase_key, and everything is ok
#define MIN
#include <algorithm>
#include <iostream>
#include "06_s01_heap.h"
#include "06_s05_priority_queue.h"
#include "../util/print.h"
#include "../util/random.h"
#include "../util/mem.h"

using namespace std;

// The priority queue provides a data filed, so this is simple
// Note array might points to the middle of an array
struct sorted_array{
  int *array;
  int size;
};

int k = 5;
int length = 10;

int main(){
  int ** data = new_2d_array<int>(k, length);
  int *standard_result = new int[k * length];
  int *result = new int[k * length];
  
  // Create random nubmer for each array and sort 
  for(int i = 0; i < k; i++){
    random_int_array_positive(data[i], length, 200);
    sort(data[i], data[i]+length);
  }

  // Copy it to a one-dimensional array
  for(int i = 0; i < k; i++)
    memcpy(standard_result + length*i, data[i], sizeof(int)*length);
  
  // sort
  sort(standard_result, standard_result + k*length);

  // initialized the heap, with an additional space
  heap<sorted_array> h(k+1);
  for(int i = 0; i < k; i++){
    sorted_array item;
    item.array = data[i];
    item.size = length;
    HeapInsert(h, item.array[0], item);
  }
  
  // sort
  int next_sorted_index = 0;  // The next elemet in the sorted array
  while(h.size != 0){
    auto item = maximum(h).second;
    extract_max(h);
    
    result[next_sorted_index] = item.array[0];
    next_sorted_index++;

    if(item.size != 1){
      item.size--;
      item.array++;
      HeapInsert(h, item.array[0], item);
    }
  }
  
  cout << "Orignal data\n";
  print_2d_int_array(data, k, length);
  cout << "Sorted data\n";
  print_int_array(result, k*length);
  // clean up
  delete_2d_array(data, k);
  delete [] standard_result;
  delete [] result;

  return 0; 
}