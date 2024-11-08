//complete this assignment, turn in for extra credit on thursday.
//Soduku puzzle to randomly populate the board
//values must add up to be 45.

#include <iostream>
#include<iomanip>
#include <cstdlib>

using namespace std;

const int rows=9;
const int columns=9;
void printMatrix(int matrix[][columns], int rows);

int main(){
	int board[rows][columns]={	{1,2,3,4,5,6,7,8,9},
								{2,3,4,5,6,7,8,9,1},
								{3,4,5,6,7,8,9,1,2},
								{4,5,6,7,8,9,1,2,3},
								{5,6,7,8,9,1,2,3,4},
							 	{6,7,8,9,1,2,3,4,5},
								{7,8,9,1,2,3,4,5,6},
								{8,9,1,2,3,4,5,6,7},
								{9,1,2,3,4,5,6,7,8}};

	printMatrix(board, rows);
	cout<<endl;

return 0;
}
void printMatrix(int matrix[][columns], int noOfRows){
	int row, col;
	for(row=0;row<noOfRows; row++){
		for(col=0;col<columns;col++)
			cout<<setw(5)<<matrix[row][col]<<"";
		cout<<endl;
	}
}
