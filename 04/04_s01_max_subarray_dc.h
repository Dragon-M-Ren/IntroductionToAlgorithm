#pragma once

#include "04_s01_max_subarray_ds.h"


ms_ret max_subarray_cross(const int* nums, int start, int mid, int end){
  // Compute left max
  int max_left = nums[mid], max_left_index = mid;
  int cur_left = 0;
  for(int i = mid; i > start - 1; i--){
    cur_left += nums[i];
    if(cur_left > max_left){
      max_left = cur_left;
      max_left_index = i;
    }
  }

  int max_right = nums[mid+1], max_right_index = mid+1;
  int cur_right = 0;
  for(int i = mid + 1; i < end + 1; i++){
    cur_right += nums[i];
    if(cur_right > max_right){
      max_right = cur_right;
      max_right_index = i;
    }
  }

  ms_ret ret = {max_left_index, max_right_index, max_left+max_right};

  return ret;
}

ms_ret max_subarray_dc(const int* nums, int start, int end){
  ms_ret ret_l, ret_r, ret_a, ret;

  // Base case, one element
  if (start == end){
    ret.start = ret.end = start;
    ret.sum = nums[start];
  }else{
    // Compute mid
    // Divide and Conquer
    int mid = (start + end)/2;
    ret_l = max_subarray_dc(nums, start, mid);
    ret_r = max_subarray_dc(nums, mid+1, end);
    ret_a = max_subarray_cross(nums, start, mid, end);
    
    // Chose the max value in the three cases
    if(ret_l.sum > ret_r.sum)
      ret = ret_l;
    else
      ret = ret_r;

    if(ret.sum < ret_a.sum)
      ret = ret_a;
  }
  
  return ret;
}

ms_ret max_subarray_interface(const int* nums, int length){
  return max_subarray_dc(nums, 0, length - 1);
}