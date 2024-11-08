//Project:	CIS021_S2019_Lab5b Allen Myers
//Module:	CIS021_S2019_Lab5b Allen Myers.cpp
//Author:	Allen Myers
//Date:		March 19th, 2019
//Purpose:	Learn how to code permutation formulas.
//			Learn how to code combinations.
//			Discover limitations of computer data types and factoring.
//

#include "stdafx.h"									//
#include "iomanip"									//
#include "iostream"									//
#include "string"									//

using namespace std;								//standard namespaces


//display large integer with commas
void PrintFInteger(__int64 _iIn)
{
	if (_iIn < 0)									//if negative
	{
		printf("-");								//negative sign
		PrintFInteger(-_iIn);						//negate to prevent - -
		return;										//return once recursion is done
	}
	if (_iIn < 1000)								//don't need a comma
	{
		printf("%d", _iIn);							//print last 3 digits
		return;										//done if no more commas needed
	}
	PrintFInteger(_iIn / 1000);						//recursive, divide by 1000 and do it again
	printf(",%03d", _iIn % 1000);					//and display the value with a comma
}
//computer factorial of input integer
_int64 _iFactorial(__int64 _iIn)
{
	if (_iIn > 20)									//_int64 will not hold values above 20!
		return -1;									//-1 will look like an error

	_int64 _iReturn = 1;							//return value
	while (_iIn > 1)									//decrement iIn down to 1
		_iReturn *= _iIn--;							//current value * decreasing input value

	return _iReturn;								//return iIn!
}
void Permutate(string*array, int& index, string& strSource, int iteration)
{
	if (iteration == strSource.length())			//add next value to array
		array[index++] = strSource;
	else
	{												//loop through chars in string
		for (int i = iteration;i < strSource.length();++i)
		{
			//swap charcters recurse to get all variations
			swap(strSource[i], strSource[iteration]);
			Permutate(array,index, strSource, iteration + 1);
			swap(strSource[i], strSource[iteration]);
		}
	}
}

int main()
{
	printf("A common permutation\n\n");				//outline
	PrintFInteger(_iFactorial(20));					//print factorial of 20!
	cout << endl << endl;							//blank line

	printf("Factorial to discover letter permutation\n\n");				//outline

	printf("How mnay 1st, 2nd, and 3rd place winner permutations with 100 contestants?\n");
	printf("P(100,3)=100x99x98= ");
	cout << endl << endl;							//blank line
	PrintFInteger(__int64(100 * 99 * 98));

	cout << endl << endl;							//blank line


	printf("How mnay with March Madness?\n");
	printf("P(68,3)=68x67x66= ");
	PrintFInteger(__int64(68 * 67 * 66));

	cout << endl << endl;							//blank line

	printf("How mnay with Bingo?\n");
	printf("P(25,5)=25x24x23x22x21= ");
	PrintFInteger(__int64(25*24*23*22*21));

	cout << endl << endl;							//blank line

	printf("How mnay with the CA Lottery?\n");
	printf("P(80,6)=80x79x78x77x76x75= ");
	PrintFInteger(__int64(80*79*78*77*76*75));

	cout << endl << endl;							//blank line

	printf("\n\n");									//blank line
	system("Pause");								//press any key to continue
	system("cls");									//clear screen

	printf("Common Combination\n\n ");
	printf("How many hands of 5 cards can be dealt from a deck of 52?\n\n");
	printf("C(total cards, hand)\n");
	printf("C(52,5)\n");
	printf(" 52!\n");
	printf("---------\n");
	printf("5! x 47!\n");
	PrintFInteger(__int64(52 * 51 * 50 * 49 * 48));
	printf("\n---------=");
	PrintFInteger(__int64(52 * 51 * 50 * 49 * 48) / _iFactorial(5));
	printf("\n");
	PrintFInteger(_iFactorial(5));

	printf("\n\n");									//blank line
	system("Pause");								//press any key to continue
	system("cls");									//clear screen

	printf("Permutations with Indistinguisable Objects\n\n");
	printf("How many ways to spell SUCCESS\n");
	int S, U, C, E;								//unique letters
	S = _iFactorial(7) / (_iFactorial(4)*_iFactorial(3));
	C = _iFactorial(4) / (_iFactorial(2)*_iFactorial(2));
	U = _iFactorial(2) / (_iFactorial(1)*_iFactorial(1));
	E = _iFactorial(1) / (_iFactorial(1)*_iFactorial(0));

	printf("\nS=%d,C=%d,U=%d, E=%d\n", S, C, U, E);

	printf("=%d\n", S*C*U*E);

	printf("\n\n");									//blank line
	system("Pause");								//press any key to continue
	system("cls");									//clear screen

	//display all variations of SUCCESS
	printf("With indistringuisable objects there are ");
	PrintFInteger(_iFactorial(7));
	printf(" items to display.\n");

	string strSuccess = "SUCCESS";					//string source
	string arrList[5040];							//target array
	int iIndex = 0;									//array index
	Permutate(arrList, iIndex, strSuccess, 0);		//fill array

	for (int i = 0;i < iIndex;i++)						//show them
		printf("%4d. %s\n",i,arrList[i].c_str());

	printf("\n\n");									//blank line
	system("Pause");								//press any key to continue
	system("cls");									//clear screen

	printf("The birthday paradox\n\n");
	printf("How many people in a room before there is a 50-50 chance that two them will have the same birthday?\n\n");

	printf("People		Chance\n");

	for (int iPeople = 1;iPeople < 100;iPeople++)		//lest look at room of 100 people
	{
		double dPairs = (iPeople*(iPeople - 1) / 2.0);	//pairs(combinations to test)
		double dUniquePair = 364.0 / 365.0;				//chances of a miss(99.7620%)
		double dChance = 1 - pow(dUniquePair, dPairs);	//chance of a match

		printf("%2d      %.4f%%\n",					//display list
			iPeople, dChance * 100);


	}



	cout << endl << endl;							//blank line
	system("Pause");								//pause before closing
    return 0;
}

