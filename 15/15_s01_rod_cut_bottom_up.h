#pragma once

#include <iostream>
#include "../util/print.h"

// The arguments' defintion is the same as top-down
void rod_cut_bottum_up(int *revenue, int *cut_point, int *price, int len, int price_len){
  for(int i = 1; i <= len; i++){
    int max_revenue = -1;
    for(int j = 1; (j <= i) && (j <= price_len); j++){
      int cur_revenue = price[j] + revenue[i - j];
      // update
      if(cur_revenue > max_revenue){
        max_revenue = cur_revenue;
        cut_point[i] = j;
      }
    }
    revenue[i] = max_revenue;
  }
}

void print_cut(int *cut_point, int len){
  while(len != 0){
    std::cout << cut_point[len] << ' ';
    len = len - cut_point[len];
  }
  std::cout << std::endl;
}

void rcbu_driver(int *price, int len, int price_len){
  int * revenue = new int[len + 1];  // index 0 is not used
  int * cut_point = new int [len + 1];
  
  revenue[0] = 0;
  for(int i = 1; i < len + 2; i++)
    revenue[i] = -1;
  
  rod_cut_bottum_up(revenue, cut_point, price, len, price_len);
  
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