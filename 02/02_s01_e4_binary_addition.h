#pragma once

// No size checking for c
// No value checking for a and b
// element 0 is the lowest-bit
void binary_addition(int *a, int *b, int *c, int len_a, int len_b, int increment = 2){
  int i;
  int inc = 0;

  for(i = 0; (i < len_a)&&(i < len_b); i++){
    int res = a[i] + b[i] + inc;
    c[i] = res%increment;
    inc = res/increment;
  }

  while(i < len_a){
    int res = a[i] + inc;
    c[i] = res%increment;
    inc = res/increment;
    i++;
  }

  while(i < len_b){
    int res = b[i] + inc;
    c[i] = res%increment;
    inc = res/increment;
    i++;
  }

  c[i] = inc;
}