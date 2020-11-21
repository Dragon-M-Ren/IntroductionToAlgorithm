#pragma once

#include <algorithm>

#include "../util/random.h"

int RandomizedSelect(int *nums, int start, int end, int target){
  if(start == end)
    return nums[start];
  
  std::swap(nums[random_int(start, end)], nums[end]);

  int pivot = nums[end];
  int smaller_end = start - 1;
  
  for(int i = start; i < end; i++){
    if(nums[i] < pivot){
      smaller_end++;
      std::swap(nums[smaller_end], nums[i]);
    }
  }
  smaller_end++;
  std::swap(nums[smaller_end], nums[end]);
  
  if(smaller_end + 1 == target)
    return pivot;
  
  if(smaller_end + 1 < target)
    return RandomizedSelect(nums, smaller_end+1, end, target);

  return RandomizedSelect(nums, start, smaller_end-1, target);
}

