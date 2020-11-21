#pragma once

#include <algorithm>

#include "../util/random.h"

int RandomizedSelectIter(int *nums, int length, int target){
  int start = 0;
  int end = length - 1;
  int ret;

  while(1){
    if(start == end){
      ret = nums[start];
      break;
    }

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
    
    if(smaller_end + 1 == target){
      ret = pivot;
      return ret;
    }
    
    if(smaller_end + 1 < target){
      start = smaller_end + 1;
    }
    else{
      end = smaller_end - 1;
    }
  }

  return ret;
}