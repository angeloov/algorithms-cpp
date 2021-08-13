#include <iostream>
using namespace std;

const int N = 8;
int B[N][N];

const int BLANK = 0;		// Blank spot on the chess board
const int QUEEN = 1;		// Spot occupied by a queen

void printChessboard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << B[i][j] << " ";
		cout << endl;
	}
}

// Check if a queen can be placed (i.e. doesn't interfere with the others)
bool canPlaceQueen(int r, int c) {
	// Sum up all the values in row r, column c, and diagonals
	int sum = 0;

	for (int i = 0; i < N; i++) sum += B[r][i]; // Sum the values in the rows
	for (int j = 0; j < N; j++) sum += B[j][c]; // Sum the values in the columns

	int startingRow = r - min(r, c);
	int startingCol = c - min(r, c);
	while (startingRow < N && startingCol < N) sum += B[startingRow++][startingCol++];

	startingRow = N - 1;
	startingCol = c - (N - 1 - r);
	while (startingRow >= 0 && startingCol < N) sum += B[startingRow--][startingCol++];

	return sum == 0;
}

// Find a permutation of queens that do not interfere with each other
bool solve(int r, int c) {
	if (c == N) return true;

	// Find a spot free for the queen to be placed
	while (!canPlaceQueen(r, c) && r < N) r++;

	// If a queen can't be put on this column the algorithm will backtrack
	// Otherwise it will mark the queen spot and solve for the next column of the board
	if (r == N) return false;
	else {
		B[r][c] = QUEEN;

		if (solve(0, c + 1)) return true;
		else { // Backtrack
			B[r][c] = BLANK;

			while (r < N - 1)
				if (solve(++r, c)) return true;
		}
	}

	return false;
}

int main() {
	solve(0, 0);
	printChessboard();
}
