#pragma once

#include "04_s01_max_subarray_ds.h"

ms_ret max_subarray_brute(const int* nums, int length){
  int max_start = 0, max_end = 0;
  int max_sum = nums[0];
  
  for(int i = 0; i  < length; i++){
    int cur_sum = 0;
    for(int j = i; j < length; j++){
      cur_sum += nums[j];
      if(cur_sum > max_sum){
        max_sum = cur_sum;
        max_start = i;
        max_end = j;
      }
    }
  }

  ms_ret ret;
  ret.start = max_start;
  ret.end = max_end;
  ret.sum = max_sum;
  
  return ret;
}