#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

vector<string> build_vector();

int get_key(string s, int offset);

template<class Data>
vector<Data> counting_sort(vector<Data> ar, const int min_key, const int max_key, function<int(Data)> get_key);

template<class Data>
vector<Data> radix_sort(vector<Data> ar, const int min_key, const int max_key, 
    const int width, function<int(Data, int)> get_key);

vector<string> sort_string(vector<string> words);

int main(){
  vector<string> words = build_vector();
  vector<string> sorted = sort_string(words);
  for(auto &s: sorted) cout << s << endl;
  return 0;
}

vector<string> build_vector(){
  vector<string> ret;

  ret.push_back("cow");
  ret.push_back("dog");
  ret.push_back("sea");
  ret.push_back("rug");
  ret.push_back("row");
  ret.push_back("mob");
  ret.push_back("box");
  ret.push_back("tab");
  ret.push_back("bar");
  ret.push_back("ear");
  ret.push_back("tar");
  ret.push_back("dig");
  ret.push_back("big");
  ret.push_back("tea");
  ret.push_back("now");
  ret.push_back("fox");

  return ret;
}

// count from the end
// offset starts from 0
int get_key(string s, int offset){
  int index = s.size() - 1 - offset;

  if(index < 0) return 0;
  else return s[index];
}

vector<string> sort_string(vector<string> words){
  int max_length = 0;
  for(auto &s: words) max_length = max_length > s.size()? max_length: s.size();
  
  return radix_sort<string>(words, 0, 200, max_length, get_key);
}

// Here is a generalized version of counting sort
template<class Data>
vector<Data> counting_sort(vector<Data> ar, const int min_key, const int max_key, function<int(Data)> get_key){
  int counter_size = max_key - min_key + 1;
  int *counter = new int[counter_size];
  for(int i = 0; i < counter_size; i++) counter[i]= 0;
  
  // count
  for(auto e: ar) counter[get_key(e) - min_key]++;
  
  // compute offset
  for(int i = 1; i < counter_size; i++) counter[i] += counter[i-1];

  // Place the element into its corresponding slot
  vector<Data> ret;
  ret.resize(ar.size());
  //ret.reserve(ar.size());
  for(int i = ar.size() - 1; i >= 0; i--){
    int key = get_key(ar[i]);
    counter[key-min_key]--;
    ret[counter[key-min_key]] = ar[i];
  }
  
  return ret;
}

template<class Data>
vector<Data> radix_sort(vector<Data> ar, const int min_key, const int max_key, 
    const int width, function<int(Data, int)> get_key){
  for(int i = 0; i < width; i++){
    std::function<int(Data)> cur_get_key = std::bind(get_key, placeholders::_1, i);
    ar = counting_sort(ar, min_key, max_key, cur_get_key);
  }
  
  return ar;
}