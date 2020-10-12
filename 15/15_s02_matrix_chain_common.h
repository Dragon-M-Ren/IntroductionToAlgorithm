#pragma once

#include <iostream>
void matrix_chain_print_result(int **cut_point, int start, int end){
  if(start == end){
    std::cout << '[' << start << ']';
    return;
  }

  std::cout << '(';
  matrix_chain_print_result(cut_point, start, cut_point[start][end]);
  matrix_chain_print_result(cut_point, cut_point[start][end]+1, end);
  std::cout << ')';
}

void matrix_chain_result(int **cut_point, int length){
  matrix_chain_print_result(cut_point, 0, length-1);
  std::cout << std::endl;
}