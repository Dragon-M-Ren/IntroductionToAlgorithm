#include "15_s01_rod_cut_td.h"

int price[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int price_len = 10;

int main(){
  rctd_driver(price, 15, price_len);

  return 0;
}
