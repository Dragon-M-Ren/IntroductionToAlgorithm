#include "06_s06_p3_young_tableaus.h"

#include <iostream>
#include <functional>
#include <algorithm>

#include "../util/print.h"
#include "../util/random.h"

using namespace std;

const int row = 5;
const int col = 8;

const int test_build_iter = 10;
const int test_extract_min_iter = 10;

void test_build();
void test_extract_min();
void test_sort();
void test_find();

int main(){
  //cout << "Test build with insert.\n";  
  //test_build();
  //cout << "Test extract min\n";
  //test_extract_min();
  //cout << "Test sort" << endl;
  //test_sort();
  cout << "Test find\n";
  test_find();
  return 0;
}

void test_build(){
  int total_elements = row * col;
  int *data = new int[total_elements];

  for(int test_iter = 0; test_iter < test_build_iter; test_iter++){
    random_int_array_positive(data, total_elements);

    young_tableaus yt(row, col);

    for(int i = 0; i < total_elements; i++){
      insert(yt, data[i]);
      if(!is_yt(yt)){
        cout << "Insert " << data[i] << " failed.\n";
        print_young_tableaus(yt);
        return;
      }
    }
    
    if(!is_yt(yt)){
      print_young_tableaus(yt);
      break;
    }
    else
     cout << "Test " << test_iter << " passed.\n";
  }
  delete [] data;
}

void test_extract_min(){
  int total_elements = row * col;
  int *data = new int[total_elements];

  random_int_array_positive(data, total_elements);
  young_tableaus yt(row, col);
  build_yt_by_insert(yt, data, total_elements);

  for(int test_iter = 0; test_iter < test_extract_min_iter; test_iter++){
    cout << "Before extract " << endl;
    print_young_tableaus(yt);
    int min = extract_min(yt);
    cout << "Extract " << min << endl;
    
    if(!is_yt(yt)){
      print_young_tableaus(yt);
      break;
    }
    else
     cout << "Test extract min " << test_iter << " passed.\n";
  }
  delete [] data;
}

void test_sort(){
  int total_elements = row * col;
  int *data = new int[total_elements];
  int *standard = new int[total_elements];
  int *result = new int[total_elements];

  random_int_array_positive(data, total_elements);
  
  memcpy(standard, data, sizeof(int) * total_elements);
  sort(standard, standard+total_elements);

  young_tableaus yt(row, col);
  build_yt_by_insert(yt, data, total_elements);

  for(int i = 0; i < total_elements; i++){
    result[i] = extract_min(yt);
  }

  if(!memcpy(standard, result, sizeof(int)*total_elements)){
    cout << "Test failed\n";
    cout << "Standard data:\n";
    print_int_array(standard, total_elements);
    cout << "Sorted output:\n";
    print_int_array(result, total_elements);
  }else{
    cout << "Test passed\n";
  }
  
}

void test_find(){
  int total_elements = row * col;
  int *data = new int[total_elements];

  random_int_array_positive(data, total_elements);
  young_tableaus yt(row, col);
  build_yt_by_insert(yt, data, total_elements);

  print_young_tableaus(yt);

  int target;
  while(cin >> target){
    pair<int, int> res = find(yt, target);
    if(res.first == -1) cout << "Not found\n";
    else
      cout << "Find: " << res.first << " " << res.second << endl;
  }
}