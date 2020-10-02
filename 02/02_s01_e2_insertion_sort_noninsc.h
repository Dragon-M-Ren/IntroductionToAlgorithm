#pragma once

#include "../util/print.h"
#include "../util/random.h"

#define swap(a, b) {int tmp = a; a = b; b = tmp;}
using namespace std;

void insertion_sort_noninsc(int *nums, int length){
  int i, j;
  for(i = 1; i < length; i++){
    int tmp = nums[i];
    for(j = i; j > 0; j--){
      if(nums[j-1] < tmp)
        nums[j] = nums[j-1];
      else
        break; 
    }
    nums[j] = tmp;
  }
}