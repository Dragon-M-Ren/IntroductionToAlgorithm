#include <iostream>
using namespace std;

int fibonacci(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;

  int *ar = new int[n+1];
  ar[0] = 0;
  ar[1] = 1;

  for(int i = 2; i <= n; i++)
    ar[i] = ar[i-1] + ar[i-2];
  
  int ret = ar[n];
  delete [] ar;

  return ret;
}

int main(){
  int n;
  
  while(cin >> n)
    cout << fibonacci(n) << endl;

  return 0;
}