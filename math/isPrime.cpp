#include <bits/stdc++.h>
using namespace std;

// Given an integer n, if n is composite return the smallest divisor of n
// else, n is prime, return 0.
int isPrime(int n) {
  // To check whether an integer n > 1 is prime we just need
  // to iterate trough the range 2, 3, 4, ... , ⌊sqrt(n)⌋
  for (int i = 2; i <= floor(sqrt(n)); i++) 
    if (n % i == 0) return i;

  return 0;
}

int main() {
  vector<int> a = {2, 3, 4, 5, 21, 31, 50};

  for (auto num : a)
    cout << num << ": " << isPrime(num) << endl;
}