#pragma once

#include <algorithm>
#include <iostream>
#include <tuple>


std::tuple<int, int> PartitionForEqual(int *nums, int start, int end){
  int pivot = nums[end];

  int smaller_end = start - 1;
  int pivot_end = start - 1;
  
  for(int i = start; i < end; i++){
    if(nums[i] < pivot){
      /*
      if(smaller_end == pivot_end){
         smaller_end++;
         pivot_end++;
         std::swap(nums[smaller_end], nums[i]);
      }*/
      smaller_end++;
      std::swap(nums[smaller_end], nums[i]);
      pivot_end++;
      // NOTE!!!!!
      // If smaller_end is the same as pivot_end
      // The the pivot exchange will change it back
      if(smaller_end != pivot_end)
        std::swap(nums[pivot_end], nums[i]);
    }
    else if(nums[i] == pivot){
      pivot_end++;
      std::swap(nums[pivot_end], nums[i]);
    }
  }
  smaller_end++;
  pivot_end++;
  std::swap(nums[pivot_end], nums[end]);

  return std::tuple<int, int>(smaller_end, pivot_end);
}

void QuickSortForEqual(int *nums, int start, int end){
  if (start >= end)
    return;

  std::tuple<int, int> mid = PartitionForEqual(nums, start, end);

  QuickSortForEqual(nums, start, std::get<0>(mid) - 1);
  QuickSortForEqual(nums, std::get<1>(mid) + 1, end);
  //std::cout << std::get<0>(mid) << "  " << std::get<0>(mid) << std::endl;
}
