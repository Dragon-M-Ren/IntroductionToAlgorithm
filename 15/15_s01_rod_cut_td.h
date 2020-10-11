#pragma once

#include <algorithm>
#include <iostream>
#include "../util/print.h"
// Rode cut top down

// revenue: The maximum revenue for each length, init to -1
// cur_point: The maximum cut point, no need to be initialized
//            Stores the length of the first part
// price: Each length rod's price
int rod_cut_top_down(int *revenue, int *cut_point, int *price, int len, int price_len){
  if(-1 != revenue[len])
    return revenue[len];
  
  if(0 == len)
    return 0;
  
  int max_revenue = 0;
  // The first part of rod can not be cutted, so it can't be larger than the defined price
  for(int i = 1; (i <= len) && (i <= price_len); i++){
    int cur_revenue = price[i] + rod_cut_top_down(revenue, cut_point, price, len - i, price_len);
    // update
    if(cur_revenue > max_revenue){
      max_revenue = cur_revenue;
      cut_point[len] = i;
    }
  }
  revenue[len] = max_revenue;

  return max_revenue;
}

void print_cut(int *cut_point, int len){
  while(len != 0){
    std::cout << cut_point[len] << ' ';
    len = len - cut_point[len];
  }
  std::cout << std::endl;
}

void rctd_driver(int *price, int len, int price_len){
  int * revenue = new int[len + 1];  // index 0 is not used
  int * cut_point = new int [len + 1];

  for(int i = 0; i < len + 2; i++)
    revenue[i] = -1;
  
  rod_cut_top_down(revenue, cut_point, price, len, price_len);
  
  std::cout << "Price array:\n";
  print_int_array(price, price_len + 1);
  std::cout << "Revenue array:\n";
  print_int_array(revenue, len + 1);
  std::cout << "Cut point array:\n ";
  print_int_array(cut_point, len + 1);
  std::cout << "Cut option: \n";
  print_cut(cut_point, len);

  delete [] revenue;
  delete [] cut_point;
}