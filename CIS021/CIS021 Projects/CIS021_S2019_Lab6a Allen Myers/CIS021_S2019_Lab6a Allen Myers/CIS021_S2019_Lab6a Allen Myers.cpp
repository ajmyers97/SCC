//Project:	CIS021_S2019_Lab6a Allen Myers
//Module:	CIS021_S2019_Lab6a Allen Myers.cpp
//Author:	Allen Myers
//Date:		April 2nd, 2019
//Purpose:	Show a matrix solution in a Visual C++ program
//			Solve a 3x3 Matrix

#include "stdafx.h"		
#include<iostream>			//i/o
#include<iomanip>			//formatting
#include<string>			//strings
using namespace std;		//names

bool bGetMatrix(int a[3][3])
{
//hard code 1's in all array elements
	for (int i = 0;i < 3;i++)
		for (int j = 0;j < 3;j++)
			a[i][j] = ((i+1)*10)+(j+1);

	return true;
}

void DisplayMatrix(int a[3][3])
{
	printf("	| %2d %2d %2d |\n", a[0][0], a[0][1], a[0][2]);
	printf("	| %2d %2d %2d |\n", a[1][0], a[1][1], a[1][2]);
	printf("a=	| %2d %2d %2d |\n", a[2][0], a[2][1], a[2][2]);
}

int SolveMatrix(int a[3][3])
{
	int iSolution = 0;		//return value

	printf("\n\nFind 4x4 Elements\n\n");
	printf("       |a22 a23|      |a21 a23|      |a21 a22|\n");
	printf("a= a11 |a32 a33| -a12 |a31 a33|	+a13 |a31 a32|\n\n");

	printf("      |%2d %2d|     |%2d %2d|     |%2d %2d|\n",
		a[1][1], a[1][2], a[1][0], a[1][2], a[1][0], a[1][1]);
	printf("a= %2d |%2d %2d| -%2d |%2d %2d| +%2d |%2d %2d|\n",
		a[0][0], a[2][1], a[2][2], a[0][1], a[2][0], a[2][2], a[0][2], a[2][0], a[2][1]);
	
	//show second step of calculations
	printf("\n\na= a11(a22 %c a33 - a32 %c a23) - a12(a21 %c a23 - a31 %c a23) + a13(a21 %c a32 - a31 %c a22)\n\n",
		249,249,249,249,249,249);

	//break it down
	printf("\n\na= %2d(%2d %c %2d - %2d %c %2d) - ",
		a[0][0], a[1][1], 249, a[2][2], a[2][1], 249, a[1][2] );
	printf("%2d(%2d %c %2d - %2d %c %2d) +",
		a[0][1], a[1][0], 249, a[2][2], a[2][0], 249, a[1][2]);
	printf("%2d(%2d %c %2d - %2d %c %2d)\n\n",
		a[0][2], a[1][0], 249, a[2][1], a[2][0], 249, a[1][1]);

	//show third step
	printf("a= a11 %c a22 %c a33 -", 249, 249);
	printf("   a11 %c a32 %c a23 -", 249, 249);
	printf("   a12 %c a21 %c a33 +", 249, 249);
	printf("   a12 %c a31 %c a23 +", 249, 249);
	printf("   a13 %c a21 %c a32 -", 249, 249);
	printf("   a13 %c a31 %c a32\n", 249, 249);
	
	printf("a= %2d %c %2d %c %2d-", a[0][0], 249, a[1][1], 249, a[2][2]);
	printf("   %2d %c %2d %c %2d-", a[0][0], 249, a[2][1], 249, a[1][2]);
	printf("   %2d %c %2d %c %2d+", a[0][1], 249, a[1][0], 249, a[2][2]);
	printf("   %2d %c %2d %c %2d+", a[0][1], 249, a[2][0], 249, a[1][2]);
	printf("   %2d %c %2d %c %2d-", a[0][2], 249, a[1][0], 249, a[2][1]);
	printf("   %2d %c %2d %c %2d\n\n", a[0][2], 249, a[2][0], 249, a[1][1]);

	//reduce
	int aa = a[0][0] * a[1][1] * a[2][2];
	int ab = a[0][0] * a[2][1] * a[1][2];
	int ac = a[0][1] * a[1][0] * a[2][2];
	int ad = a[0][1] * a[2][0] * a[1][2];
	int ae = a[0][2] * a[1][0] * a[2][1];
	int af = a[0][2] * a[2][0] * a[1][1];

	printf("a= %2d - %2d - %2d + %2d + %2d - %2d\n",
		aa, ab, ac, ad, ae, af);
	iSolution = aa - ab - ac + ad + ae - af;

	return iSolution;
}


int main()
{
	int a[3][3];			//3x3 matrix
	int iSolution;			//solution value

	if (bGetMatrix(a))		//fill the matrix
	{
		DisplayMatrix(a);	//display raw values

		//solve the matrix
		iSolution = SolveMatrix(a);
		printf("\na=%d\n", iSolution);		//show solution

	}





	cout << endl << endl;	//output a blank line
	system("Pause");		//pause before closing
    return 0;
}

