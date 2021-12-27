#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &a) {
	const int n = a.size();
	
	for (int i = 0; i < n; i++) {
		int min = i;
		
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min]) min = j;
		}
		
		swap(a[i], a[min]);
	}
}

int main() {
	vector<int> a = {1, 0, 3, 7, 2, 3, 8, 2, 4};	

	selectionSort(a);
	
	for (int el : a) cout << el << " ";
	cout << endl;
}