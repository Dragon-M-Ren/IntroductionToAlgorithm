#include "15_s04_lcs_top_down.h"

const char *x = "ABCBDAB";
const char *y = "BDCABA";

int lenx = 7;
int leny = 6;

int main(){
  lcs_td_driver(x, y, lenx, leny);

  return 0;
}