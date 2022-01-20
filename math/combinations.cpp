#include <bits/stdc++.h>
using namespace std;

void printV(vector<int> &a) {
  for (auto e : a)
    cout << e << " ";
  
  cout << endl;
}

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
 
int C(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void combination(int r, int n) {
  vector<int> s(r);
  for (int i = 0; i < r; i++)
    s[i] = i+1;

  
  printV(s); // Print the first permutation
  
  for (int i = 1; i < C(n,r); i++) {
    int m = r-1;
    int maxVal = n;
    
    // Find the rightmost element not at its maximum value
    while (s[m] == maxVal) {
      m--;
      maxVal--;
    }
    
    // Increment the rightmost element
    s[m]++;
    
    // The rest of the elements are the successors of s[m]
    for (int j = m+1; j < r; j++) 
      s[j] = s[j-1] + 1;
  
    printV(s);
  }
}

int main() {
  combination(3, 5);
}

