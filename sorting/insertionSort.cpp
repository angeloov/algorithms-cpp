#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &a) {
  for (int i = 1; i < a.size(); i++) {
    int j = i;

    while (j > 0 && (a[j] < a[j - 1])) {
      swap(a[j], a[j - 1]);
      j--;
    }
  }
}

int main() {
  vector<int> a = {1, 2, 9, 8, 4, 7, 5};
  insertionSort(a);

  for (int el : a) cout << el << " ";
  cout << endl;
}