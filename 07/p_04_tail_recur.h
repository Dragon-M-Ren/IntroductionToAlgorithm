#pragma once

#include <algorithm>

// Copied from quick_sort.h
int Partition(int *nums, int start, int end){
  int pivot = nums[end];
  int smaller_end = start - 1;
  
  // Not include the end
  for(int i = start; i < end; i++){
    if(nums[i] < pivot){
      smaller_end++;
      std::swap(nums[smaller_end], nums[i]);
    }
  }
  smaller_end++;
  std::swap(nums[smaller_end], nums[end]);

  return smaller_end;
}

void QuickSortTailRecur(int * nums, int start, int end){
  while(start < end){
    // partition and recursively sort the first part
    int mid = Partition(nums, start, end);
    QuickSortTailRecur(nums, start, mid - 1);
    start = mid + 1;
  }
}

void QuickSortTailRecurOptimizedForDepth(int *nums, int start, int end){
 while(start < end){
    // partition and recursively sort the first part
    int mid = Partition(nums, start, end);
    
    // The first part is smaller
    if(mid - start < end - mid){
       QuickSortTailRecurOptimizedForDepth(nums, start, mid - 1);
       start = mid + 1;
    }
    // The latter part is smaller
    else{
      QuickSortTailRecurOptimizedForDepth(nums, mid + 1, end);
      end = mid - 1;
    }
  } 
}