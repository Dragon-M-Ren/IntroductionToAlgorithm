#pragma once

// Return the middle of the three number
int mid_of_three(int a, int b, int c){
  int x = a - b;
  int y = b - c;
  int z = a - c;

  if(x * y > 0)
    return b;
  else if( x * z > 0)
    return c;
  
  return a;
}


// Return the index of the median
// Count start from 0
int mid_of_three_index(int a, int b, int c){
  int x = a - b;
  int y = b - c;
  int z = a - c;

  if(x * y > 0)
    return 1;
  else if( x * z > 0)
    return 2;
  
  return 0;
}