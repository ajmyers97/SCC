//Module:	CIS021_S2019_FinalExam Allen Myers.cpp
//Project:	CIS021_S2019_FinalExam Allen Myers
//Author:	Allen Myers
//Date:		May 21st, 2019
//Purpose:	Demonstrate the ability to create a C++ program in Microsoft Visual Studio.
//			Demonstrate knowledge of probability calculations.
//			Demonstrate the ability to navigate a moderately large block of data.
//			Demonstrate the proper use of a vector in C++.
//
#include "stdafx.h"

//return random number between iMin and iMax
//returns the char val becuase passed as a character
int GetRandomInt(int iMin, int iMax)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<>dist(iMin, iMax);

	return dist(gen);
}

int main()
{
	string a1, b1, c1;									//reference string, randomly created
	string a2, b2, c2;									//variable string, randomly created
	int iMatches = 0;									//number of matches

	printf("----Comparing Random Char Strings----\n");	//title
	printf("Goal: to find the probability that a character appears during testing.\n");
	printf("The system will generate 6 random characters.\n");
	printf("It will analyze the characthers to find matches.\n");
	printf("Once matches are found, it will increment the counter and output the number.\n");

	cout << endl << endl;								//output blank line

	printf("A1	B1	C1	A2	B2	C2\n");		//roller header

	for (int i = 0;i < LIST_SIZE;i++)					//loop
	{
		for (int j = 0; j < 3; j++)	 					// 3 chars in each combination
		{
			a1 = GetRandomInt(65, 90);					//random value A-Z
			b1 = GetRandomInt(65, 90);					//random value A-Z
			c1 = GetRandomInt(65, 90);					//random value A-Z

			a2 = GetRandomInt(65, 90);					//random value A-Z
			b2 = GetRandomInt(65, 90);					//random value A-Z
			c2 = GetRandomInt(65, 90);					//random value A-Z

			//can't decide if these belong inside the J loop or outside the JLoop???
			//print out the values
			cout << a1 << "	" << b1 << "	" << c1 << "	" << a2 << "	" << b2 << "	" << c2 << "\n";

			//compare the values of char set 1 to the values of char set 2
			//if (a1 == a2 || a1 == b2 || a1 == c2 || b1 == a2 || b1 == b2 || b1 == c2 || c1 == a2 || c1 == b2 || c1 == c2)										//do they match?
				//iMatches++;
		}
		//can't decide if these belong inside the J loop or outside the JLoop???
		//print out the values
		//cout << a1 << "	" << b1 << "	" << c1 << "	" << a2 << "	" << b2 << "	" << c2 << "\n";

		//compare the values of char set 1 to the values of char set 2
		if (a1 == a2 || a1 == b2 || a1 == c2 || b1 == a2 || b1 == b2 || b1 == c2 || c1 == a2 || c1 == b2 || c1 == c2)										//do they match?
			iMatches++;
	}
	cout << "Number of Matches found: " << iMatches;


	cout << endl << endl;								//output blank line
	system("Pause");									//pause before closing
	return 0;
}



