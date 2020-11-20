#pragma once

#include <cmath>
#include <utility>
#include <functional>
#include <memory>
#include <iostream>

#include "../util/print.h"
#include "08_s02_counting_sort.h"

// Get a digit in a decimal number
int GetDigit(int num, int offset){
  num /= pow(10, offset);
  return num%10;
}

// Use decimal number
void RadixSort(int *nums, int *res, int length, int width){
  for(int i = 0; i < width; i++){
    std::function<int(int)> get_key = std::bind(GetDigit, std::placeholders::_1, i);
    CountingSortKeyed(nums, res, length, 0, 100, get_key);
    
    // Copy the sorted value to the original array
    // The algorithm does't sort in place
    memcpy(nums, res, sizeof(int)*length);
  }
  memcpy(res, nums, sizeof(int)*length);
}