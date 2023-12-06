#include <sorts.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void AddLine(string line) {
  std::ofstream out;                // ïîòîê äëÿ çàïèñè
  out.open("stats.csv", ios::app);  // îòêðûâàåì ôàéë äëÿ çàïèñè
  if (out.is_open()) {
    out << line << endl;
  }
  out.close();
}

vector<int> GetOrderedArray(int size) {
  vector<int> arr(size);
  for (int i = 0; i < size; ++i) {
    arr[i] = i;
  }
  return arr;
}

vector<int> GetReOrderedArray(int size) {
  vector<int> arr(size);
  for (int i = size-1; i >=0; --i) {
    arr[i] = i;
  }
  return arr;
}

void GetStats() {
  AddLine("sort_type;array_length;sorted;comparison;copy");
  int sizes[] = {1000, 2000, 3000,  4000,  5000,  6000,  7000,
                 8000, 9000, 10000, 25000, 50000, 100000};
  string InsertSort = "InsertSort";
  string QuickSort = "QuickSort";
  string CombSort = "CombSort";
  Sorts::MyVector stats;
  Sorts::Stats InsertSortStats;
  Sorts::Stats QuickSortStats;
  Sorts::Stats CombSortStats;
  for (int i = 0; i < 13; ++i) {
    cout << "--------- SIZE: " << sizes[i] << "---------------" << endl;
    string middle_part = ";" + to_string(sizes[i]) + ";0;";
    for (int j = 0; j < 100; ++j) {
      cout << "Cycle: "<< j << endl;
      vector<int> arr1 = stats.GetRandomVector(sizes[i]);
      vector<int> arr2 = arr1;
      InsertSortStats += Sorts::InsertSort(arr1);
      arr1 = arr2;
      QuickSortStats += Sorts::QuickSort(arr2);
      CombSortStats += Sorts::CombSort(arr1);
    }
    InsertSortStats /= 100;
    QuickSortStats /= 100;
    CombSortStats /= 100;
    
    AddLine(InsertSort + middle_part +
            to_string(InsertSortStats.comparison_count) + ";" +
            to_string(InsertSortStats.copy_count));
    AddLine(QuickSort + middle_part +
            to_string(QuickSortStats.comparison_count) + ";" +
            to_string(QuickSortStats.copy_count));
    AddLine(CombSort + middle_part +
            to_string(CombSortStats.comparison_count) + ";" +
            to_string(CombSortStats.copy_count));
    middle_part = ";" + to_string(sizes[i]) + ";1;";
    vector<int> arr = GetOrderedArray(sizes[i]);
    QuickSortStats = Sorts::QuickSort(arr);
    InsertSortStats = Sorts::InsertSort(arr);
    CombSortStats = Sorts::CombSort(arr);
    AddLine(InsertSort + middle_part +
            to_string(InsertSortStats.comparison_count) + ";" +
            to_string(InsertSortStats.copy_count));
    AddLine(QuickSort + middle_part +
            to_string(QuickSortStats.comparison_count) + ";" +
            to_string(QuickSortStats.copy_count));
    AddLine(CombSort + middle_part + to_string(CombSortStats.comparison_count) +
            ";" + to_string(CombSortStats.copy_count));
    middle_part = ";" + to_string(sizes[i]) + ";-1;";
    arr = GetReOrderedArray(sizes[i]);
    QuickSortStats = Sorts::QuickSort(arr);
    InsertSortStats = Sorts::InsertSort(arr);
    CombSortStats = Sorts::CombSort(arr);
    AddLine(InsertSort + middle_part +
            to_string(InsertSortStats.comparison_count) + ";" +
            to_string(InsertSortStats.copy_count));
    AddLine(QuickSort + middle_part +
            to_string(QuickSortStats.comparison_count) + ";" +
            to_string(QuickSortStats.copy_count));
    AddLine(CombSort + middle_part + to_string(CombSortStats.comparison_count) +
            ";" + to_string(CombSortStats.copy_count));
  
  }
}


int main() {
  GetStats();
  /*std::vector<int> arr;
  arr = vector.GetRandomVector(60000);
  Sorts::Stats sorts = Sorts::QuickSort(arr);*/
  /* for (int i = 0; i < arr.size(); ++i) {
     cout << arr.at(i) << " ";
   }*/
  /*cout << endl
       << "comp: " << sorts.comparison_count << " copy: " << sorts.copy_count;*/


  return 0;
}