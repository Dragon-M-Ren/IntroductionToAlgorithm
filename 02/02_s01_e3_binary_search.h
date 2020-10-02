int binary_search(const int *nums, int length, int target){
  int start = 0;
  int end = length - 1;

  while(start <= end){
    int mid = (start + end)/2;
    if(nums[mid] == target)
      return mid;
    
    if(nums[mid] < target)
      start = mid + 1;
    
    else
      end = mid - 1;
  }

  return -1;
}