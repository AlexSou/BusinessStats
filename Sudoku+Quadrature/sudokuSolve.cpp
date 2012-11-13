//Alejandro Soulier as4094
//Input: Sudoku, incompleted.
//Output: Sudoku, completed.

#include <math.h>
#include <iostream>
using namespace std;

//Sample Sudoku. 0 means empty.
int sudIn [9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9},
};
int sudSol [9][9];

void sudokuSolve();
bool solveElem(int col, int row);
bool combDoneRowCol(int no, int row, int col);
bool combDoneRow(int no, int row);
bool combDoneCol(int no, int col);
bool combDoneSol (int no, int row, int col);



void sudokuSolve() {

	bool solved = solveElem(0,0); // Start recursive algorithm.
	if (solved) { //Solved, print sodoku.
		for(int i; i<9; i++){
			for(int j; j<9; j++){
				cout << sudSol[i][j] << " ";
			}
			cout << endl;
		}
	}
	else { // No solution.
		cout << "Can't be solved." << endl;
	}
}

bool solveElem(int col, int row) { //Solve for 1 element.
	if(col >= 9){
		return (solveElem(0, row+1));
	}
	else if (row >= 9){
		return true;
	}
	else if(sudIn[col][row] != 0){
		return (solveElem(col+1, row));
	}

	for (int i = 1; i <= 9; i++){
		if (combDoneRowCol(i, row, col)){
			sudSol[row][col] = i;
		}
		if(solveElem(row+1, col)){
			return true;
		}
	}

	sudSol[col][row] = 0;
	return false;
}

bool combDoneRowCol(int no, int row, int col){
	//Check row col correct.
	bool ans;
	ans =  combDoneSol(no, row, col) && combDoneCol(no, col) && combDoneRow(no, row);
	return ans;
}

bool combDoneRow(int no, int row){
	//Check row  correct.
	for(int i; i<9; i++){
		if((abs(sudSol[row][i])) == no){
			return false;
		}
	}
	return true;
}

bool combDoneCol(int no, int col){
	//Check  col correct.
	for(int i; i<9; i++){
		if((abs(sudSol[i][col])) == no){
			return false;
		}
	}
	return true;
}

bool combDoneSol (int no, int row, int col) {
	// Solving algorithm.
	int sq1 = (col/3) *3;
	int sq2 = (row/3) *3; //Int, so mod division.

	for (int i = sq2; i < (sq2+3); i++) {
		for(int j = sq1; j < (sq1+3); j++){
			if( (abs(sudSol[i][j])) == no ) {
				return false;
			}
		}
	}
	return true;
}

int main() { //Main
	sudokuSolve();
	return 0;
}
// End of code.
