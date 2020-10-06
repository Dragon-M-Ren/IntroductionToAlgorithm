#pragma once

#include <algorithm>

#include "../util/statistic.h"

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

int PartitionMidThree(int *nums, int start, int end){
  int mid = (start + end)/2;

  int start_value = nums[start];
  int mid_value = nums[mid];
  int end_value = nums[end];

  int mid_index = mid_of_three_index(start_value, mid_value, end_value);
  

  // Swap with the last number
  if(0 == mid_index)
    std::swap(nums[start], nums[end]);
  else if(1 == mid_index)
    std::swap(nums[mid], nums[end]);
  
  // Use the original paritition algorithm
  return Partition(nums, start, end);
}

int PartitionRandom(int *nums, int start, int end){
  std::swap(nums[random_int(start, end)], nums[end]);
  
  return Partition(nums, start, end);
}

void QuickSort(int *nums, int start, int end){
  // if start == end, base case, do nothing and return
  if(start < end){
    int mid = Partition(nums, start, end);
    QuickSort(nums, start, mid - 1);
    QuickSort(nums, mid + 1, end);
  }
}

void QuickSortMidOfThre(int *nums, int start, int end){
  // if start == end, base case, do nothing and return
  if(start < end){
    int mid = PartitionMidThree(nums, start, end);
    QuickSortMidOfThre(nums, start, mid - 1);
    QuickSortMidOfThre(nums, mid + 1, end);
  }
}

void QuickSortRandom(int *nums, int start, int end){
  // if start == end, base case, do nothing and return
  if(start < end){
    int mid = PartitionRandom(nums, start, end);
    QuickSortRandom(nums, start, mid - 1);
    QuickSortRandom(nums, mid + 1, end);
  }
}
void QuickSortInterface(int *nums, int length){
  QuickSort(nums, 0, length - 1);
}

void QuickSortMidOfThreeInterface(int *nums, int length){
  QuickSortMidOfThre(nums, 0, length - 1);
}

void QuickSortRandomInterface(int *nums, int length){
  QuickSortRandom(nums, 0, length - 1);
}