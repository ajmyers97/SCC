//Project:	CIS021_S2019_Lab3b Allen Myers.cpp : Defines the entry point for the console application.
//Module:	CIS021_S2019_Lab3b Allen Myers.cpp
//Author:	Allen Myers
//Date:		Feb 7th, 2019
//Purpose:	Demonstrate theorems usign functions
//
//


#include "stdafx.h"
#include "windows.h"		//for SYSTEMTIME
#include <iostream>			//basic i/o
#include <sstream>			//for string stream
#include <iomanip>			//console formatting
#include <string>			//string library
#include <bitset>			//for the bitset in the parity

using namespace std;		//use standard namespaces

void DivisionAlgorithm()	//use div and mod to create pseudo random values
{
	int a, d, q, r;			//dividend, divisor, quotient, remainder

	cout << "Division Algorithm\n\n";
	cout << "Fixed Values:\n";
	a = 101;				//dividend
	d = 11;					//divisor

	q = a / d;				//q is quotient
	r = a % d;				//r is remainder

	//display results
	printf("a=%d \n", a);
	printf("d=%d \n", d);
	printf("q=%d \n", q);
	printf("r=%d \n", r);

	//using system time for pseudorandom values
	cout << "System time-1\n";
	SYSTEMTIME tLocalTime;						//structure holds time(YY,MM,DD,HH,MM,SS)
	GetLocalTime(&tLocalTime);					//local clock time
	a = tLocalTime.wMilliseconds;
	d = tLocalTime.wSecond;

	q = a / d;									//divide milliseconds by seconds
	r = a % d;									//remainder
												//display results
	printf("a=%d \n", a);						//print the values
	printf("d=%d \n", d);
	printf("q=%d \n", q);
	printf("r=%d \n", r);
	
	for (int i = 0; i < d * 1000; i++)			//pseudorandom delay
		printf("Delay:%i%c", i, 0x0D);	
	cout << endl << endl;						//print a blank line
	//
	//cout << "System Time-2\n";

	//GetLocalTime(&LocalTime);				//get new time

	//GetLocalTime(&tLocalTime);			//local clock time
	//a = tLocalTime.wMilliseconds;
	//d = tLocalTime.wSecond;

	//q = a / d;							//divide milliseconds by seconds
	//r = a % d;							//remainder
	//										//display results
	//printf("a=%d \n", a);					//print the values
	//printf("d=%d \n", d);
	//printf("q=%d \n", q);
	//printf("r=%d \n", r);

}
bool isPrime(int a)
{
	for (int i = 2; i < a / 2; i++)				//from 2 up to half of a number
		if (a%i == 0)							//if mod is 0
			return false;						//this is false and not prime

	return true;								//yes, i am prime
}
void PrimeFactorization()
{
	int a;										//number to be factored(user input)
	int iBase;									//modified number
	cout << "Prime Factorization\n\n";
	cout << "Enter a positive integer: ";
	cin >> a;									//get the user input

	//this following code will allow you to output all primes from 2 to 1000
		//for (a = 2; a < 1000; a++)
		//{
		//	cout << a << ":";
		//	isPrime(a) ? cout << "isPrime!\n" : cout << "Not Prime!\n";
		//	cout << " ";
		//}
	
	if (isPrime(a))
		cout << endl << a <<
		"is a prime number and cannot be factored. \n\n";
	else
	{
		cout << a << "=";						//"35= "

		iBase = a;								//iBase is a copy of user input, it will change
		while (iBase > 1)						//continue until no longer favorable
		{
			//start with 2, up to 1/2 of user input
			for(int i=2; i<=a/2;i++)
				if (iBase%i==0)					//is this index a factor?
				if (isPrime(i))					//is this index a prime bumber?
				{
					cout << i << "x";			//display the factor
					iBase = iBase/i;			//adjust the base, remove factor
					break;						//jump out of for loop

				}
			printf("%c%c", 0x08, 0x08);			//2 backspaces
			cout << endl << endl;				//blank line
		}
	}
}
void FindPrimes()
{
	int a = 1;									//value to test for prime
												//INT_MAX=2,147,483,647

	cout << "Listing prime numbers\n";
	cout << "1";
	for (a = 2; a < 1000; a++)					// test values from 2 to a big number(in this case 1000)
	{
		if (isPrime(a))							//if this is a prime number
			cout <<"," <<a;						//then list it
	}

}
void ModularExponentiation()
{
	int b, e, m;		//base, exponent, divisor
		int iTemp = 1;
	cout << "ModularExponetiation\n\n";
	cout << "Enter a base integer: ";
	cin >> b;
	cout << "Enter an exponent integer: ";
	cin >> e;
	cout << "Enter a divisor integer: ";
	cin >> m;

	iTemp = pow(b, e);				//temp= b to the e power

	printf("b^e mod m\n");
	printf("%i ^ %i mod %i = %i\n",b,e,m, 
		iTemp % m
		);
//	iTemp = pow(b, e) % m;			//Modular Exponentiation formula

}
//void Hash()
//{
//	int h, k, m;					//key, max
//	int iLow = 210000000;			//210,000,000
//	int iHigh = 211000000;			//211,000,000
//	int iSolution;					//result of calculaion
//
//	cout << "Hashing Function h(k) = k mod m  \n\n:";
//	cout << "h= the hash value of the numeric value k \n";
//	cout << "k= the subject being hashed\n";
//	cout << "m= max number of values to be hashed \n\n";
//
//	printf("Finding hash values between %i and %i \n",
//		iLow, iHigh);
//	m = iHigh - iLow;				//range, number of values
//	for (k = iLow; k < iHigh; k += 777001)
//	{
//		iSolution = (h* k) - (k % m);
//			printf("h(m)= %i mod %i = %i \n",
//				h, k, k, m, iSolution);
//	}
//
//
//}
void PseudorandomNumber()
{

	int a = pow(7, 5);			//multiplier
	int c = 0;					//increment
	int m = pow(2, 31) - 1;		//modulous
	int x0 = 3;					//seed starting point
	int x1;						//next random

	cout << "Pseudo Random Number\n\n";
	cout<< "X1=(a*X0+c)mod m \n\n";
	for (int i = 1; i < 10; i++)			//create random numbers
	{
		x1 = (a*x0 + c) % m;				//x1 is pseudo random number
		printf("(a*x0 + c) % m \n");
		printf("%i * %i + %i)%% %i= %i\n", a, x0, c, m, x1);
		x0 = x1;							//increment to next value
	}
}
void Parity()
{
	string strInput;			//user input
	string strBin;				//bit stream
	stringstream ss;			//convert bitset to string
	int iBitCount = 0;			//how many 1's 
	cout << "Parity\n\n";
	cout << "Enter a string: ";
	cin >> strInput;			//et user input
	cout << "Parity=";	
	for (int i = 0; i < strInput.length(); i++)	//roll through string
	{
		ss<< bitset<8>(strInput[i]);	//convert bitset to string
		strBin = ss.str();				//move result to string
	
	}
	for (int i = 0; i < strBin.length(); i++)	//roll through string
		if (strBin[i] == '1')					//1 or 0's, is this a 1?
			iBitCount++;						//yes? count it.

	cout << strBin << "=" <<iBitCount<<"="<<					//output
		bitset<8>(iBitCount);
}
int main()
{
	//DivisionAlgorithm();
	//PrimeFactorization();
	//FindPrimes();
	//ModularExponentiation();
	// Hash();
	//PseudorandomNumber();
	Parity();

	cout << endl << endl;						//blaknk line
	system("pause");							//pause before closing
    return 0;
}

