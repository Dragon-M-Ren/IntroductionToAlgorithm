#pragma once
#include <algorithm>

using namespace std;

void selection_sort(int *nums, int length){
  // The last element doesn't need to be sorted
  for(int i = 0; i < length - 1; i++){
    int min_value = nums[i];
    int min_index = i;
    for(int j = i + 1; j < length; j++){
      if(min_value > nums[j]){
        min_value = nums[j];
        min_index = j;
      }
    }
    // exchange
    swap(nums[i], nums[min_index]);
  }
}