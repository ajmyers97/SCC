//Project:	CIS021_S2019_Lab4c Allen Myers
//Module:	CIS021_S2019_Lab4c Allen Myers.cpp
//Author:	Allen Myers
//Date:		March 5th, 2019
//Purpose:	Learn how recursion works.
//			Learn how to code recursive functions.
//			Troubleshoot common mistakes in recursive logic.
//
#include "stdafx.h"
#include <iomanip>								//formatting
#include<iostream>								//console i/o
#include<stdarg.h>								//variable length argument list

using namespace std;							//standard namespaces

int Factorial(int N)							//return the factorial of N
{
	if (N == 0)									//rewind when factoring 0
		return 1;								

	return N*Factorial(N - 1);					//multiply reduction numbers
}
int Power(int iBase, int iExponent)				//return iBase^iExponent
{
	if(iExponent == 0)							//done when e=0
		return 1;

	return iBase*Power(iBase, iExponent - 1);	//recursive
}
int AddNumbers(int iNumArgs, ...)				//variable length argument list
{
	int iCount = 0;								//set counter to 0, also return value
	int iBurn;									//for moving ahead in arg list

	va_list vl;									//define argument list

	va_start(vl, iNumArgs);						//start/reset argument list

//	iBurn = va_arg(vl, int);					//show arguments
//	iBurn = va_arg(vl, int);					//show arguments
//	iBurn = va_arg(vl, int);					//show arguments

	if (iNumArgs == 2)								//2nd time through
		iCount = va_arg(vl, int) + va_arg(vl, int);	//add the 2 values
	else if (iNumArgs == 3)							//1st time thorugh
	{
		iBurn = va_arg(vl, int);					//burn the first 2 args
		iBurn = va_arg(vl, int);

		iCount =								//send last argument to 2nd recursion
			AddNumbers(2, iCount, va_arg(vl, int));
	}
	else
		return -1;
	va_end(vl);									//stop moving through argument list

	return iCount;								//return sum of arguments
}
int AddNumbers(int iList[], int iSize, int iPos)	//count values in an array
{
	printf("%d\n", iPos);							//display the numbers on the screen

	if (iSize == iPos)											//at end of array
		return 0;

	return iList[iPos] + AddNumbers(iList, iSize,iPos+1);	//add item in array
}
int Fibonacci(int iLocation)
{
	if (iLocation < 2)									//below 2 is the stopping point
		return 1;	

	//calculate the sequence number
	return Fibonacci(iLocation - 1) + Fibonacci(iLocation - 2);

}
//original copy of below function
//int Fibonacci(int i1st, int i2nd, int iLocation)
//{
//	if (iLocation < 2)									//below 2 is the stopping point
//		return 1;
//
//	//calculate the sequence number
//	return Fibonacci(i1st, i2nd, iLocation - 1) +
//		Fibonacci(i1st, i2nd, iLocation - 2);
//
//}

int Fibonacci(int i1st, int i2nd, int iLocation)
{
	if (iLocation+1 < 2)									//below 2 is the stopping point
		return 1;

	//calculate the sequence number
	return Fibonacci(i1st, i2nd, iLocation - 2) +
		Fibonacci(i1st, i2nd, iLocation - 1);

}
int main()
{
	//Begin Factorial Recursion
	int iIn;									//user input
	printf("Factorial Recursion\n");			//title
	printf("Enter an integer: ");				//prompt for user input
	cin >> iIn;									//get the user input

	printf("The factorial of %d is %d\n",		//find and display the factorial
		iIn,									//user input
		Factorial(iIn));						//find the factorial
	cout << endl << endl;						//blank line
	//End Factorial Recursion

	//Begin Exponential Recursion
	int iIn1,iIn2;									//user input
	printf("Exponential Recursion\n");				//title
	printf("Enter a base integer: ");				//get user input
	cin >> iIn1;
	printf("Enter an exponent integer: ");
	cin >> iIn2;
	printf("%d to the power of %d is %d\n",			//do the math for the exponent
		iIn1, iIn2,
		Power(iIn1, iIn2));
	cout << endl << endl;							//blank line
	//End Exponential Recursion

	//Begin Addition Recursion v1
	//this is hard coded, values should be changed to be able to be variable
	//1,2,3 can be changed to adjust value
	printf("Addition Recursion V1\n");				//title
	printf("1+2+3= %d",								//variable length arg list
		AddNumbers(3, 1, 2, 3));					//sum of values
	cout << endl << endl;							//blank line
	//End Addition Recursion v1

	//Begin Addition Recursion v2-this overloads the AddNumbers from V1
	printf("Addition Recursion V2\n");				//title
	int NumArray[] = { 1,2,3,4,5,6,7,8,9,10 };		//list of numbers

	printf("Adding a list of numbers gives us: %d\n",
		AddNumbers(NumArray, sizeof(NumArray) / sizeof(int), 0));
	cout << endl << endl;							//blank line
	//End Addition Recursion v2

	//Begin Fibonacci Sequence Using Recursion
	int iIn3, iIn4, iIn5;							//user input data
	printf("Enter 1st number in sequence:");		//get user input
	cin >> iIn3;
	printf("Enter 2nd number in sequence:");		//get user input for lower limit
	cin >> iIn4;
	printf("Enter number of sequences to seek:");	//get user input for upper limit
	cin >> iIn5;

	printf("Fibonacci Sequence number is %d\n",		//find Fibonacci sequence of seek number
		//Fibonacci(iIn5));
		Fibonacci(iIn3,iIn4,iIn5));
	//End Fibonacci Sequence Using Recursion



	cout << endl << endl;						//blank line
	system("Pause");							//pause before closing
    return 0;
}

