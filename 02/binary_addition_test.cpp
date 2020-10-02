#include <iostream>
#include <algorithm>

#include "../util/random.h"
#include "../util/print.h"

#include "02_s01_e4_binary_addition.h"

using namespace std;

int len_a = 6;
int len_b = 8;

int main(){
  int *a = new int[len_a];
  int *b = new int[len_b];
  
  int len_c = max(len_a, len_b) + 1;
  int *c = new int[len_c];
  
  random_int_array_positive(a, len_a, 2);
  random_int_array_positive(b, len_b, 2);

  cout << "Array 1: " << endl;
  print_int_array(a, len_a);
  cout << "Array 2: " << endl;
  print_int_array(b, len_b);

  binary_addition(a, b, c, len_a, len_b);

  cout << "Result: "  << endl;
  print_int_array(c, len_c);
 
  delete [] a;
  delete [] b;
  delete [] c;

  return 0;
}