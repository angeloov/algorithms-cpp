#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int key) {
  int lo = 0;
  int hi = arr.size() - 1;

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (key < arr[mid])
      hi = mid - 1;
    else if (key > arr[mid])
      lo = mid + 1;
    else
      return mid;
  }

  return -1;
}

int main() {
  vector<int> v = {1, 2, 3, 5, 12, 15, 16, 17, 18, 20};

  cout << binarySearch(v, 5) << endl;
}