#include <iostream>

#include "../util/print.h"
#include "../util/random.h"

using std::cout;
using std::cin;
using std::endl;

// The return value is the inversions counted in this merge
int inversion_merge(int *nums, int start, int mid, int end){
  int len_1 = mid - start + 1;
  int len_2 = end - mid;
  int * tmp_1 = new int[len_1];
  int * tmp_2 = new int[len_2];
  int ret = 0;


  for(int i = 0; i < len_1; i++)
    tmp_1[i] = nums[start + i];
  for(int i = 0; i < len_2; i++)
    tmp_2[i] = nums[mid + 1 + i];
  
  int i = 0, j = 0, target = start;
  while((i < len_1) &&(j < len_2)){
    if(tmp_1[i] < tmp_2[j]){
      nums[target] = tmp_1[i];
      i++;
    }
    else{
      nums[target] = tmp_2[j];
      j++;
      ret += len_1 - i;
    }
    target++;
  }

  while(i < len_1){
    nums[target] = tmp_1[i];
    i++;
    target++;
  }

  while(j < len_2){
    nums[target] = tmp_2[j];
    j++;
    target++;
  }

  delete [] tmp_1;
  delete [] tmp_2;

  return ret;
}


// The retuen value is the number of inversion
// The original array is changed
int inversion(int *nums, int start, int end){
  // Not base problem, slove recursively 
  int ret = 0;
  if(start < end){
    int mid = (start + end)/2;
    ret += inversion(nums, start, mid);
    ret += inversion(nums, mid + 1, end);
    ret += inversion_merge(nums, start, mid, end);
  }
  return ret;
}


// A trival implementation
// The orginal array is not changed
int trival_inversion(int *nums, int length){
  int ret = 0;

  for(int i = 0; i < length - 1; i++){
    for(int j = i+1; j < length; j++){
      if(nums[i] > nums[j])
        ret++;
    }
  }

  return ret;
}

// test settings
int length = 10;

int main(){
  int *nums = new int[length];
  random_int_array(nums,length);
  
  cout << "Origianl Array: " << endl;
  print_int_array(nums, 10);

  int inversion_trival = trival_inversion(nums, length);
  int inversion_merge = inversion(nums, 0, length - 1);
  
  cout << "Counted by trivial implementation: " << inversion_trival << endl;
  cout << "Counted by merge inversion: " << inversion_merge << endl;
  if(inversion_merge == inversion_trival)
    cout << "succeed\n";
  else
    cout << "failed\n";
  
  delete [] nums;
  return 0;
}