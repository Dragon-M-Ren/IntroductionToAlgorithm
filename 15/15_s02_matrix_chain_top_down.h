#pragma once

#include <iostream>
#include <climits>

#include "15_s02_matrix_chain_common.h"
#include "../util/mem.h"
#include "../util/print.h"

#define UNAVAILABLE -1
/// The dimension array start from 0
/// The matrx chain start from 0 and end with n-1
/// See the comment of the bottom-up version
int matrix_chain_top_down(int ** cost, int ** cut_point, int *dimension, int start, int end, int len){
  if(UNAVAILABLE != cost[start][end])
    return cost[start][end];
  
  int min_cost = INT32_MAX;
  int min_cut_point; // no need to initialize this

  for(int cur_cut_point = start; cur_cut_point < end; cur_cut_point++){
    int cur_cost = matrix_chain_top_down(cost, cut_point, dimension, start, cur_cut_point, len) + 
                   matrix_chain_top_down(cost, cut_point, dimension, cur_cut_point+1, end, len) + 
                   dimension[start]*dimension[cur_cut_point+1]*dimension[end+1];
    if(cur_cost < min_cost){
      min_cost = cur_cost;
      min_cut_point = cur_cut_point;
    }
  }
  // Update
  cost[start][end] = min_cost;
  cut_point[start][end] = min_cut_point;

  return min_cost;
}


void mctd_driver(int *dimension, int len){
  int **cost = new_2d_int_array(len, len);
  int **cut_point = new_2d_int_array(len, len);

  // Init cost array
  for(int i = 0; i < len; i++)
    for(int j = 0; j < len; j++)
      cost[i][j] = UNAVAILABLE;

  // init the diagonal of cost
  for(int i = 0; i < len; i++)
    cost[i][i] = 0;

  matrix_chain_top_down(cost, cut_point, dimension, 0, len-1, len);

  std::cout << "Dimension array: \n";
  print_int_array(dimension, len);
  std::cout << "Cost matrix: \n";
  print_2d_int_array(cost, len, len);
  std::cout << "cut_point matrix: \n";
  print_2d_int_array(cut_point, len, len);

  matrix_chain_result(cut_point, len);

  delete_2d_array(cost, len);
  delete_2d_array(cut_point, len);
}