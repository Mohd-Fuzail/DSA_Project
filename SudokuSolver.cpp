// SudokuSolver.cpp
#include<iostream>
using namespace std;

void Print(int board[][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isCorrect(int board[][9], int i, int j, int val) {
	// row check
	for (int c = 0; c < 9; c++) {
		if (board[i][c] == val) {
			return false;
		}
	}

	// Col Check
	for (int r = 0; r < 9; r++) {
		if (board[r][j] == val) {
			return false;
		}
	}

	// Box Check
	int si = i - i % 3;
	int sj = j - j % 3;

	for (int r = si; r < si + 3; r++) {
		for (int c = sj; c < sj + 3; c++) {
			if(board[r][c]==val)
				return false;
		}
	}

return true;
}

bool SudokuSolver(int board[][9], int i, int j) {

	//Base Case
	if ( i == 8 && j == 9) {
		return true;
	}
	// some Checks

	if (j == 9) {
		return SudokuSolver(board, i + 1, 0);
	}

	if (board[i][j] != 0) {
		return SudokuSolver(board, i, j + 1);
	}

	for (int val = 1; val <= 9; val++) {
		if (isCorrect(board, i, j, val)) {
			board[i][j] = val;
			bool ans = SudokuSolver(board, i, j + 1);
			if (ans)
				return true;
			board[i][j] = 0;
		}
	}
	return false;
}


int main() {
	int board[9][9] = {
		{0, 0, 7, 1, 0, 0, 0, 6, 0},
		{1, 0, 5, 2, 0, 8, 0, 0, 0},
		{6, 0, 0, 0, 0, 7, 1, 2, 0},
		{3, 1, 2, 4, 0, 5, 0, 0, 8},
		{0, 0, 6, 0, 9, 0, 2, 0, 0},
		{0, 0, 0, 0, 0, 3, 0, 0, 1},
		{0, 0, 1, 0, 0, 4, 9, 8, 6},
		{8, 0, 3, 9, 0, 6, 0, 0, 0},
		{0, 6, 0, 0, 8, 2, 7, 0, 3},
	};

	SudokuSolver(board,0,0);

	Print(board);

	return 0;
}


