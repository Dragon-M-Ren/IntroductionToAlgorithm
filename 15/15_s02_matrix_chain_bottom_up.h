#pragma once

#include <iostream>
#include <climits>
#include "../util/mem.h"
#include "../util/print.h"

// The index of matrix start from 0
// The row dim and column dim for matrix k has index k and k+1
void matrix_chain_bottom_up(int ** cost, int ** cut_point, int *dimension, int start, int end, int len){
  // cur_len is the current length of the subproblems
  for(int cur_len = 2; cur_len <= len; cur_len++){
    // Start point of each subproblem
    for(int cur_start = 0; cur_start < len - cur_len + 1; cur_start++){
      // since a local value is ued to maintain the min value of each step
      // Initialization of the cost matrix is not needed except the diagonal
      int min_cost = INT32_MAX;
      int min_cut_point = -1; // The cost and cur_point will be updated at least once
      int cur_end = cur_start + cur_len - 1;
      // cut_point, note it include start and exclude end
      for(int cur_cut_point = cur_start; cur_cut_point < cur_end; cur_cut_point++){
        int cur_cost = cost[cur_start][cur_cut_point] + cost[cur_cut_point+1][cur_end] + dimension[cur_start]*dimension[cur_cut_point+1]*dimension[cur_end+1];
        if(cur_cost < min_cost){
          min_cost = cur_cost;
          min_cut_point = cur_cut_point;
        }
      }
      // Update
      cost[cur_start][cur_end] = min_cost;
      cut_point[cur_start][cur_end] = min_cut_point;
    }
  }
}

void mcbu_driver(int *dimension, int len){
  int **cost = new_2d_int_array(len, len);
  int **cut_point = new_2d_int_array(len, len);

  // init the diagonal of cost
  for(int i = 0; i < len; i++)
    cost[i][i] = 0;

  matrix_chain_bottom_up(cost, cut_point, dimension, 0, len-1, len);

  std::cout << "Dimension array: \n";
  print_int_array(dimension, len);
  std::cout << "Cost matrix: \n";
  print_2d_int_array(cost, len, len);
  std::cout << "cut_point matrix: \n";
  print_2d_int_array(cut_point, len, len);
}