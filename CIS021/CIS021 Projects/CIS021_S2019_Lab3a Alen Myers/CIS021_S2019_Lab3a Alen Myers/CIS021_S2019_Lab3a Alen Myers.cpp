//Project:	CIS021_S2019_Lab3a Alen Myers
//Module:	CIS021_S2019_Lab3a Alen Myers.cpp	
//Author:	Allen Myers
//Date:		Feb 5th, 2019
//Purpose:	Review class creation.
//			Perform operations on a template class.
//			Learn how to convert algorithms into virtual functions.

#include "stdafx.h"
#define FILE_SIZE 1000	//# of lines in the input file

bool LoadFile(int A[])
{
	ifstream inFile;						//handle to file
	string strFilespec =					//name of file
		"CIS021_S2019_Lab3a_data.txt";
	string strIn;							//a line from the file
	int iIndex = 0;							//index in array

	inFile.open(strFilespec);				//open the file

	if (inFile.is_open())					//did the file open?
	{
		getline(inFile, strIn);				//get the first line from file
		while (inFile.good())				//while the file is open and not EOF
		{
			A[iIndex++] =						//load the array
				atoi(strIn.c_str());		//converts a tchar to integer


			getline(inFile, strIn);			//read the next file
		}

		inFile.close();						//close the file
		return true;						//file is good
	}
	return false;							//file not found
}


int main()
{

	int iArray[FILE_SIZE];		//hold integers from the file
	int iInput;					//user input(for search)

	if (LoadFile(iArray))		//load file into array
	{
		//find the maximum element in a finite sequence
		printf("The largest number in the data file is: %d.",
			Functions::Largest(iArray,FILE_SIZE));
		cout << endl << endl;						//endl chars


		//perform a bubble sort
		printf("Performing a simple bubble short.\n ");
		printf("Before: ");
			//dump array
			for (int i = 0; i < FILE_SIZE; i++)
				cout << iArray[i] << " ";

			Functions::Sort(iArray, FILE_SIZE);		//sort the array

			printf("\nAfter: ");

			//dump array
			for (int i = 0; i < FILE_SIZE; i++)
				cout << iArray[i] << " ";



		//search an ordered list for a value
			printf("Enter a number to find: ");					//prompt for input
			cin >> iInput;										//get user input

			Functions::Search(iArray, FILE_SIZE, iInput) ?		//
			printf("Found\n") :									//
				printf("Not Found\n");							//

	}
	else
		cout << "File could not be found.";

	cout << endl << endl;		//blank line
	system("Pause");			//pause before closing
    return 0;
}

