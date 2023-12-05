#include <sorts.h>
#include <vector>
#include <iostream>
using namespace std;


int main() {
  vector<int> arr{5, 6, 1, 7, 10, 18, 51, 13, 0, -1};
  Sorts::InsertSort(arr);
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr.at(i) << " ";
  }


  return 0; }