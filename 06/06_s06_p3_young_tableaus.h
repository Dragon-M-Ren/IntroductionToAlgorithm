#pragma once

#include <utility>

#define MIN -1
#define MAX 999

#include "../util/mem.h"
#include "../util/print.h"

// The elements should start from 0 and end with 998
// So -1 represents negitive-infinity
//    999 represents positive-inifnity
struct young_tableaus{
  int ** table;
  int row;
  int col;
  
  // create a table and set it to empty
  young_tableaus(int r, int c): row(r), col(c){
    table = new_2d_int_array(row, col);
    for(int i = 0; i < row; i++)
      for(int j = 0; j < col; j++)
        table[i][j] = MAX;
  }

  ~young_tableaus(){
    delete_2d_array(table, row);
  }
};

// Check if a table is young tableaus
bool is_yt(young_tableaus &yt){
  int row = yt.row;
  int col = yt.col;
  int **table = yt.table;

  for(int i = 0; i < row; i++)
    for(int j = 0; j < col; j++){
      if(i+1 < row && table[i+1][j] < table[i][j])
        return false;
      if(j+1 < col && table[i][j+1] < table[i][j])
        return false;
    }

  return true;
}


void insert(young_tableaus &yt, int key){
  int row = yt.row;
  int col = yt.col;
  int **table = yt.table;

  // The key is out of bound
  if(key <= MIN || key >= MAX) return;
  // The table is full
  if(yt.table[yt.row-1][yt.col-1] != MAX) return;
  
  // insert
  table[row-1][col-1] = key;
  int cur_row = row - 1;
  int cur_col = col - 1;

  // compare the new key with its up and left
  // if both of them are less than the key, return
  // or switch with the larger one
  while(cur_row > 0 && cur_col > 0){
    // the element had been put on the right position
    if(table[cur_row-1][cur_col] <= key && table[cur_row][cur_col-1] <= key) return;
    if(table[cur_row-1][cur_col] > table[cur_row][cur_col-1]){
      std::swap(table[cur_row-1][cur_col], table[cur_row][cur_col]);
      cur_row--;
    }else{
      std::swap(table[cur_row][cur_col-1], table[cur_row][cur_col]);
      cur_col--;
    }
  }
  
  // deal with margianl conditions
  while(cur_row > 0 && table[cur_row-1][cur_col] > key){
    std::swap(table[cur_row-1][cur_col], table[cur_row][cur_col]);
    cur_row--; 
  }
  while(cur_col > 0 && table[cur_row][cur_col-1] > key){
    std::swap(table[cur_row][cur_col-1], table[cur_row][cur_col]);
    cur_col--;
  }

}

void build_yt_by_insert(young_tableaus &yt, int *data, int len){
  for(int i = 0; i < len; i++)
    insert(yt, data[i]);
}
void young_tableaus_ify(young_tableaus &yt, int cur_row, int cur_col){
  int row = yt.row;
  int col = yt.col;
  int **table = yt.table;
  int key = table[cur_row][cur_col];

  while(cur_row + 1 < row && cur_col + 1 < col){
    if(table[cur_row+1][cur_col] >= key && table[cur_row][cur_col+1] >= key) return;
    if(table[cur_row+1][cur_col] < table[cur_row][cur_col+1]){
      std::swap(table[cur_row+1][cur_col], table[cur_row][cur_col]);
      cur_row++;
    }else{
      std::swap(table[cur_row][cur_col+1], table[cur_row][cur_col]);
      cur_col++;
    }
  }

  while(cur_row + 1 < row && table[cur_row+1][cur_col] < key){
    std::swap(table[cur_row+1][cur_col], table[cur_row][cur_col]);
    cur_row++;
  }
  while(cur_col + 1 < col && table[cur_row][cur_col+1] < key){
    std::swap(table[cur_row][cur_col+1], table[cur_row][cur_col]);
    cur_col++;
  }
}

int extract_min(young_tableaus &yt){
  int row = yt.row;
  int col = yt.col;
  int **table = yt.table;

  // the table is empty
  if(table[0][0] == MAX) return -1;
  
  // get the min value
  int ret = table[0][0];

  // find a maximal value and set it to root
  int i = 0, j = 0; // i for row and j for col
  while(i + 1 < row && table[i+1][0] != MAX) i++;
  while(j + 1 < col && table[i][j+1] != MAX) j++;
  
  // move the maximal value to root and set the original slot to 0
  table[0][0] = table[i][j];
  table[i][j] = MAX;
  
  young_tableaus_ify(yt, 0, 0);

  return ret;
}

std::pair<int, int> find(young_tableaus &yt, int target){
  int cur_row = 0, cur_col = 0;

  int row = yt.row;
  int col = yt.col;
  int **table = yt.table; 
  
  // track along the fist row
  // move right right until the current element is not smaller than the element
  // or it encounters the end
  while(cur_col < col-1 && table[0][cur_col] < target) cur_col++;
  
  // Don't move out-of-bound
  while(cur_row < row && cur_col >= 0){
    // Find the target, return
    if(table[cur_row][cur_col] == target)
      return std::pair<int, int>(cur_row, cur_col);
    
    // The element is larger than target, move left
    if(table[cur_row][cur_col] > target) cur_col--;
    // The element is smaller than target, move down
    else cur_row++;
  }

  return std::pair<int, int>(-1, -1);
}


void print_young_tableaus(young_tableaus &yt){
  print_2d_int_array(yt.table, yt.row, yt.col, yt.col + 1);
}