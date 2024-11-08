//Project:		CIS021_S2019_HW5 Allen Myers
//Module:		CIS021_S2019_HW5 Allen Myers.cpp
//Author:		Allen Myers
//Date:			March 28th, 2019
//Purpose:		Demonstrate counting principles.
//				Manipulate data into all possible configurations.
//				Solve a complex problem.
//

#include "stdafx.h"
#include <iostream>										// i/o
#include<iomanip>										//formatting
#include<string>										//string library
#include <cctype>										//c functions
#include <algorithm>									//fancy math
#include<fstream>										//file output

using namespace std;										//standard namespaces

//removes non alphebtical chars from the user input
//converts all uppercase chars to lowercase
//prints as single string
string removeNonAlphaChars(string userInputString)
{
	string returnStringA;									//return value

	const std::string str = userInputString;				//str is the userinput
	{
		// complicated: after erasing, stay at the same position for the next char
		// but cater to the erase having reduced the size of the string
		std::string b = str;								//local references
															//remove nonalpha chars
		for (std::size_t i = 0; i < b.size(); ++i)
			while (!std::isalpha(b[i]) && i < b.size()) b.erase(i, 1);


		transform(b.begin(), b.end(), b.begin(), ::tolower);//convert uppercase to lowercase

		returnStringA = b;
	}
	return returnStringA;
}
string findPermutationsList(string convertedUserString)
{
    string s = convertedUserString;

    sort(s.begin(), s.end());
    cout << s << endl;
	while (next_permutation(s.begin(), s.end()))
       cout << s << endl;
	return s;
}
int findPermutationsCount(string convertedUserString)
{
	string s = convertedUserString;
	int count = 0;

	sort(s.begin(), s.end());
	count++;
	while (next_permutation(s.begin(), s.end()))
	count++;

	return count;
}

void printToFile(string finalString)
{
	string textFileString = finalString;
	std::ofstream file;

	file.open("CIS021_S2019_HW5_Data.txt");      //open a file

	file << textFileString;       //write to it

	file.close();           //close it
}

int main()
{
	//step2-Prompt the user for a string.
	string userInput;
	string resolvedUserInput;
	printf("Enter a string:	");								//prompt user for a string
	std::getline(cin,userInput);							//get the user input

	//output the string that was converted and removed of UPPERCASE
	//chars, other non-alphabetical chars and whitespaces.
	printf("The converted string value is: ");
	resolvedUserInput=removeNonAlphaChars(userInput);		//convert the user input
	cout << resolvedUserInput;
	cout << endl;									//output blank line

	//step 3-Determine the possible number of permutations.
	int permValue=findPermutationsCount(resolvedUserInput);
	printf("\nThe possible number of permutations is: %d\n", permValue);
	cout << endl;									//output blank line


	//step 4-Output the list of anagrams.
	printf("The permutation options are:\n");
//	findPermutationsList(resolvedUserInput);

	cout << endl << endl;									//output blank line

	////step 4-Output the list of anagrams.
	//printf("The permutation options are:\n");
	//{
	//	ofstream myfile("CIS021_S2019_HW5_Data.txt");
	//	if (myfile.is_open())

	//		for (int i = 0; i < permValue; i++)
	//		{
	//			myfile << findPermutationsList(resolvedUserInput);
	//			cout << endl;
	//		}
	//		myfile.close();
	//}
	//cout << endl << endl;									//output blank line



	//step 5-Display a blank line and pause before closing the program.
	cout << endl << endl;									//output blank line
	system("Pause");										//pause before closing
    return 0;
}

