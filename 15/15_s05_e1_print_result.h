#pragma once

#include <iostream>

void print_one_line(int **root, int start, int end, int parent){
  if(end < start){
    //base case, dummy keys
    std::cout << "d[" << << ']' << "is the" << << " child of" << parent << std::endl; 
    return;
  }

  std::cout << "k[" << root[start][end] << "]" << " is the " << << " child of" << parent << std::endl;
  
}
void print_result(int **root, int start, int end){
  std::cout << "k[" << root[start][end] << "]" << "is the root\n";

  int left_end = root[start][end]-1;
  int right_start = root[start][end]+1;

   
}

void print_result_recursive(int **root, int start, int end){
  if(end < start){
    // base case, process dummy keys
  }
}
