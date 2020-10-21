#include "15_s05_obt_bottom_up.h"

// Note the first element in the key probability array is not used
double key_p[] = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
double dummy_p[] = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};

int key_len = 5;

int main(){
  obt_bu_driver(key_p, dummy_p, key_len);
  return 0;
}