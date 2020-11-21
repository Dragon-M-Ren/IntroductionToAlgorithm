#pragma once

#include <tuple>

int Minimum(int *ar, int length){
  int min_index = 0;

  if(0 == length)
    return -1;
  
  for(int i = 1; i < length; i++)
    if(ar[min_index] > ar[i])
      min_index = i;
  
  return min_index;
}

int Maximum(int *ar, int length){
  int max_index = 0;
  
  if(0 == length)
    return -1;
  for(int i = 1; i < length; i++){
    if(ar[max_index] < ar[i])
      max_index = i;
  }

  return max_index;
}

std::tuple<int, int> MinMax(int *ar, int length){
  int max_index, min_index, i;
  
  // check limit
  if(0 == length)
    return std::tuple<int, int>(-1, -1);

  // even
  if(length % 2 == 0){
    i = 2;
    if(ar[0] > ar[1]){
      max_index = ar[0];
      min_index = ar[1];
    }
    else{
      max_index = ar[1];
      min_index = ar[0];
    }
  }
  // odd
  else{
    i = 1;
    max_index = min_index = 0;
  }

  for(; i < length; i += 2){
    if(ar[i] > ar[i+1]){
      if(ar[i] > ar[max_index])
        max_index = i;
      if(ar[i+1] < ar[min_index])
        min_index = i + 1;
    }
    else{
      if(ar[i] < ar[min_index])
        min_index = i;
      if(ar[i+1] > ar[max_index])
        max_index = i + 1;
    }
  }

  return std::tuple<int, int>(max_index, min_index);
}