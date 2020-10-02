#include <algorithm>
using std::swap;


void bubble_sort(int *nums, int length){
  for(int i = 0; i < length - 2; i++){
    for(int j = length - 1; j > i; j--){
      if(nums[j] < nums[j-1])
        swap(nums[j], nums[j-1]);
    }
  }
}