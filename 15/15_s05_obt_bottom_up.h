#pragma once

#include <iostream>
#include <climits>

#include "../util/mem.h"
#include "../util/print.h"
// The key shoulbe be sorted and we don't care the key's actual value
// The index of key_p start from 1
// The index of dummy_p start from 0
double obt_bottom_up(double ** cost, double ** weight, int **root, double *key_p, double *dummy_p, int len){
  // Init the cost and weight arrray
  for(int i = 1; i <= len+1; i++){
    cost[i][i-1] = dummy_p[i-1];
    weight[i][i-1] = dummy_p[i-1];
  }
  
  // The length should start from 1
  // Compute the 'second' base case
  for(int l = 1; l <= len; l++){
    for(int start = 1; start <= len - l + 1; start++){
      int end = start + l - 1;
      std::cout << "start: " << start << " end: " << end << std::endl;
      double min_cost = -1; //  UNAVAILABLE
      int cut_point;
      // update weight matrix
      weight[start][end] = weight[start][end-1] + key_p[end] + dummy_p[end];
      // loop through current root
      for(int r = start; r <= end; r++){
        double cur_cost = cost[start][r-1] + cost[r+1][end] + weight[start][end];
        // update
        if((min_cost == -1) || (cur_cost < min_cost)){
          min_cost = cur_cost;
          cut_point = r;
        }
      }
      // Update to table
      cost[start][end] = min_cost;
      root[start][end] = cut_point;
    }
  }
  return cost[1][len];
}

void obt_bu_driver(double *key_p, double *dummy_p, int len){
  double ** weight = new_2d_array<double>(len + 2, len + 2);
  double ** cost = new_2d_array<double>(len + 2, len + 2);
  int ** root = new_2d_array<int>(len +1, len + 1); // the first row and col is not used
  
  double total_cost = obt_bottom_up(cost, weight, root, key_p, dummy_p, len);
  
  std::cout << "Cost matrix: \n";
  print_2d_array<double>(cost, len + 2, len + 2);
  std::cout << "Weight matrix: \n";
  print_2d_array<double>(weight, len + 2, len + 2);
  std::cout << "Root matrix: \n";
  print_2d_int_array(root, len+1, len+1);

  std::cout << "Total cost: " << total_cost << std::endl;
}