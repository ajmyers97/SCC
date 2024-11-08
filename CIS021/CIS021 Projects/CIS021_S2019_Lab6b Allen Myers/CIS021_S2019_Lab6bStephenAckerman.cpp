// Project: CIS021_S2019_Lab6b Stephen Ackerman
// Module:	CIS021_S2019_Lab6b Stephen Ackerman.cpp
// Author:	Stephen Ackerman
// Date:	4/4/2019
// Purpose:	Learn to sort data - not in order, but by specification
//			Learn set operations

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

#define DATA_SIZE 298			// number of records in data file

struct CitiesStruct
{
	std::string City;			// name of city
	std::string State;			// name of US state
	int Population;				// population of city
};

bool LoadFile(CitiesStruct Cities[])
{
	std::ifstream inFile;		// input file handle

	inFile.open("CIS021_S2019_Lab6b_data.txt");			// open the file

	if (inFile.is_open())
	{
		std::string strCity, strState, strPop;			// hold data from file

		for (int i = 0; i < DATA_SIZE; i++)				// read DATA_SIZE # of lines
		{
			std::getline(inFile, strCity, ',');				// read city
			std::getline(inFile, strState, ',');			// read state
			std::getline(inFile, strPop, '\n');				// read population

			Cities[i].City = strCity;
			Cities[i].State = strState;
			Cities[i].Population = stoi(strPop);
		}

		inFile.close();
		return true;
	}
	else
	{
		printf("Unable to open file.\n");
	}
	return false;
}

void Subset(CitiesStruct Cities[])
{
	std::string strFilter;						// user input

	printf("Please enter the name of a US State: ");
	std::getline(std::cin, strFilter);			// get user input

	std::transform(strFilter.begin(), strFilter.end(), strFilter.begin(), ::toupper);

	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::string strState = Cities[i].State;	// local copy of state name
		std::transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		if (strFilter == strState)				// if they are the same
		{
			printf("%s, %s, %d\n", Cities[i].City.c_str(), Cities[i].State.c_str(), Cities[i].Population);
		}
	}
}

void Not(CitiesStruct Cities[])
{
	std::string strFilter;						// user input

	printf("Please enter the name of a US State: ");
	std::getline(std::cin, strFilter);			// get user input

	std::transform(strFilter.begin(), strFilter.end(), strFilter.begin(), ::toupper);

	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::string strState = Cities[i].State;	// local copy of state name
		std::transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		if (strFilter != strState)				// if they are the same
		{
			printf("%s, %s, %d\n", Cities[i].City.c_str(), Cities[i].State.c_str(), Cities[i].Population);
		}
	}
}

void And(CitiesStruct Cities[])
{
	std::string strFilter[2];						// user input

	printf("Please enter the name of a US State: ");
	std::getline(std::cin, strFilter[0]);			// get user input
	printf("Please enter another US State: ");
	std::getline(std::cin, strFilter[1]);			// get user input

	for (int i = 0; i < 2; i++)
	{
		std::transform(strFilter[i].begin(), strFilter[i].end(), strFilter[i].begin(), ::toupper);
	}

	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::string strState = Cities[i].State;	// local copy of state name
		std::transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		if (strFilter[0] == strState || strFilter[1] == strState)				// if they are the same
		{
			printf("%s, %s, %d\n", Cities[i].City.c_str(), Cities[i].State.c_str(), Cities[i].Population);
		}
	}
}

void Or(CitiesStruct Cities[])
{
	std::string strFilter[2];						// user input

	printf("Please enter the name of a US State: ");
	std::getline(std::cin, strFilter[0]);			// get user input
	printf("Please enter another US State: ");
	std::getline(std::cin, strFilter[1]);			// get user input

	for (int i = 0; i < 2; i++)
	{
		std::transform(strFilter[i].begin(), strFilter[i].end(), strFilter[i].begin(), ::toupper);
	}

	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::string strState = Cities[i].State;	// local copy of state name
		std::transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		if (strFilter[0] == strState)				// if they are the same
		{
			printf("%s, %s, %d\n", Cities[i].City.c_str(), Cities[i].State.c_str(), Cities[i].Population);
		}
	}

	std::cout << std::endl << std::endl;		// blank line

	for (int i = 0; i < DATA_SIZE; i++)
	{
		std::string strState = Cities[i].State;	// local copy of state name
		std::transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		if (strFilter[1] == strState)				// if they are the same
		{
			printf("%s, %s, %d\n", Cities[i].City.c_str(), Cities[i].State.c_str(), Cities[i].Population);
		}
	}
}

int main()
{
	CitiesStruct Cities[DATA_SIZE];

	if (LoadFile(Cities))
	{
		//Subset(Cities);				// get subset of array
		//Not(Cities);				// get NOT subset of array
		//And(Cities);				// get 2 states
		Or(Cities);					// get one or the other state
	}

	std::cout << std::endl << std::endl;
	system("Pause");
    return 0;
}

