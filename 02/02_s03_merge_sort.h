void merge(int *nums, int start, int mid, int end){
  int len_1 = mid - start + 1;
  int len_2 = end - mid;
  int * tmp_1 = new int[len_1];
  int * tmp_2 = new int[len_2];


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
}

void merge_sort(int *nums, int start, int end){
  // Not base problem, slove recursively 
  if(start < end){
    int mid = (start + end)/2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);
    merge(nums, start, mid, end);
  }
}

void merge_sort_interface(int *nums, int length){
  merge_sort(nums, 0, length - 1);
}