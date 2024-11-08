//Project:	CIS021_S2019_Lab5a Allen Myers
//Module:	CIS021_S2019_Lab5a Allen Myers.cpp
//Author:	Allen Myers
//Date:		March 14th, 2019
//Purpose:	Learn how to demonstrate simple counting principles.
//			Learn how to demonstrate the Pigeonhole Pinciple.
//
#include "stdafx.h"
#include "iomanip"
#include "iostream"
#include "string"

using namespace std;								//standard namespaces

//display large integer with commas
void PrintFInteger(__int64 _iIn)
{
	if (_iIn < 0)									//if negative
	{
		printf("-");
		PrintFInteger(-_iIn);						//negate to prevent - -
		return;
	}
	if (_iIn < 1000)								//don't need a comma
	{
		printf("%d", _iIn);							//print last 3 digits
		return;
	}
	PrintFInteger(_iIn / 1000);						//recursive, divide by 1000 and do it again
	printf(",%03d", _iIn % 1000);					//and display the value with a comma
}

int main()
{
	//begin phone number calculations
	const int N = 8;								//N pssible values
	const int Y = 2;								//
	const int X = 10;								//

	//begin old system calculations
	int iAreaCode = N*Y*X;							//how many area codes
	int iOfficeCode = N*N*X;						//how many office codes
	int iStationCode = X*X*X*X;						//how many station codes

	printf("The total number of phone numbers under the old system(NYX) (NNX-XXXX) is:\n");
	PrintFInteger(iAreaCode*iOfficeCode*iStationCode);
	cout << endl;
	//end old system math


	//begin new system calculations
	int iAreaCodeNew = N*X*X;						//how many area codes
	int iOfficeCodeNew = N*X*X;						//how many office codes
	int iStationCodeNew = X*X*X*X;					//how many station codes

	printf("The total number of phone numbers under the new system(NXX) (NXX-XXXX) is:\n");
	PrintFInteger(iAreaCodeNew*iOfficeCodeNew*iStationCodeNew);
	cout << endl;
	//end new system math
	//end phone number calculations

	//begin CA license plate number calculations
	const int iPrefix = 9;							//1ABC123-prefix 1-9
	const int iLetter1 = 26;						//
	const int iLetter2 = 26;						//
	const int iLetter3 = 26;						//
	const int iNumber1 = 10;						//
	const int iNumber2 = 10;						//
	const int iNumber3 = 10;						//

	printf("Total Passenger car license plate numbers possible in CA(1ABC123) is:\n");
	PrintFInteger(iPrefix*iLetter1*iLetter2*iLetter3*iNumber1*iNumber2*iNumber3);
	cout << endl << endl;
	//end CA license plate number calculations

	//ca license plate numbers based on class types
	printf("Total Passenger car license plate numbers possible in CA(1ABC123) based on class is:\n");
	int iClassA = (pow(2, 7) - 1)*(pow(2, 24) - 2);
	int iClassB = (pow(2, 14))*(pow(2, 16) - 2);
	int iClassC = (pow(2, 21))*(pow(2, 8) - 2);
	printf("Class A= ");
	PrintFInteger(iClassA);
	cout << endl;

	printf("Class B= ");
	PrintFInteger(iClassB);
	cout << endl;

	printf("Class C= ");
	PrintFInteger(iClassC);
	cout << endl;
	cout << endl << endl;



	//Subtraction rule: picks up when possibility of duplicates
	//if we have 350 applicants, 147 business majors, 220 CS majors, 51 both

	const int iApplicants = 350;						//job applicants
	const int iCS = 220;
	const int iBus = 147;
	const int iBoth = 51;

	printf("If %d apllied for the job, %d have neither a CS or Business degree.\n",
		iApplicants, iApplicants - (iCS + iBus - iBoth));
	cout << endl << endl;

	//division rule: the seating problem
	printf("Seating problem with a table of 4: %f\n",
		(1.0*((4*3*2*1)/4)));
	cout << endl << endl;

	//pigeonhole principle:max even distribution, 72 pigeons, and 24 pigeon holes

	printf("With 72 pigeon's in 24 pigeon holes, at least 1 hole must have more than 1 pigeon. \n ");

	cout << endl << endl;

	//round house principle:every player plays every other player

	//same birth/initals problem
	const int iPopulation = 370000000;				//ca population
	const int iNumberDaysOfYear = 366;				//# days in year
	const int iNumAlphabet = 26;					//26 letters in alphabet
	const int iInitials = 3;						//FML initals in name

	int iPossibility=(iNumberDaysOfYear*(iNumAlphabet*iInitials));//no, not 26+26+26
	iPossibility = iNumberDaysOfYear*(pow(iNumAlphabet,iInitials));

	printf("How many people in California has the same birth date and initials?\n");
	printf("%d, %f", iPossibility,(1.0*iPossibility/iPopulation)*100.0);

	cout << endl << endl;

	//sum rule
	//IP addresses problem
	printf("Counting IP Addresses");
	cout << endl << endl;

	const int iMaxOctal = 511;							//
	_int64 iMaxIP4=pow(iMaxOctal,4);
	printf("The number of possible IP4 addresses is:");
	PrintFInteger(iMaxIP4);
	cout << endl << endl;




	cout << endl << endl;							//end line
	system("Pause");								//pause before closing
    return 0;
}

