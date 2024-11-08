//project:	CIS021_S2019_Lab6b Allen Myers
//module:	CIS021_S2019_Lab6b Allen Myers.cpp
//Author:	Allen Myers
//Date:		April 4th, 2019
//Purpose:	Learn to sort data - not in order, but by specification.
//			Learn set operations.

#include "stdafx.h"			//
#include<iostream>			//i/o
#include<iomanip>			//formatting
#include<string>			//strings
#include<fstream>			//file i/o
#include<sstream>			//file i/o
#include<algorithm>			//toupper

using namespace std;		//std::

#define DATA_SIZE 298		//# of records in the file

struct CitiesStruct 
{
	string City;			//name of city
	string State;			//name of state
	int Population;			//population of city
};

bool LoadFile(CitiesStruct Cities[])
{
	ifstream inFile;		//input file handle
							//open the file
	inFile.open("CIS021_S2019_Lab6b_data.txt");
	if (inFile.is_open())	//did the file open
	{
							//data from the file
		string strCity, strState, strPop;

		for (int i = 0;i < DATA_SIZE;i++)
		{
							//get the city, state, pop data
			getline(inFile, strCity, ',');
			getline(inFile, strState, ',');
			getline(inFile, strPop, '\n');
							//store the city,state,pop data
			Cities[i].City = strCity;
			Cities[i].State = strState;
			Cities[i].Population = stoi(strPop);
		}

		inFile.close();		//close the file when done
		return true;
	}
	else
		printf("Unable to open the requested file.\n");

	return false;
}
void Subset(CitiesStruct Cities[])
{
	string strFilter;		//user input

	printf("Please enter the name of a US State: ");
	getline(cin, strFilter);//get user input

							//uppercase the user input
	transform(strFilter.begin(), strFilter.end(), strFilter.begin(), ::toupper);

	for (int i = 0;i < DATA_SIZE;i++)
	{
							//local copy of state name
		string strState = Cities[i].State;
		transform(strState.begin(), strState.end(), strState.begin(), ::toupper);
							
							//are they the same?
		if (strFilter == strState)
		{
			printf("%s,%s,%d\n",
				Cities[i].City.c_str(), 
				Cities[i].State.c_str(),
				Cities[i].Population);
		}
	}
}

//not one state
void NOT(CitiesStruct Cities[])
{
	string strFilter;		//user input

	printf("Please enter the name of a US State: ");
	getline(cin, strFilter);//get user input

							//uppercase the user input
	transform(strFilter.begin(), strFilter.end(), strFilter.begin(), ::toupper);

	for (int i = 0;i < DATA_SIZE;i++)
	{
		//local copy of state name
		string strState = Cities[i].State;
		transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		//are they the same? I think NOT!
		if (strFilter != strState)
		{
			printf("%s,%s,%d\n",
				Cities[i].City.c_str(),
				Cities[i].State.c_str(),
				Cities[i].Population);
		}
	}
}
//two states
void AND(CitiesStruct Cities[])
{
	string strFilter[2];		//user input

	printf("Please enter the name of a US State: ");
	getline(cin, strFilter[0]);//get user input
	printf("Please enter the name of another US State: ");
	getline(cin, strFilter[1]);//get user input

							//uppercase the user input
	transform(strFilter[0].begin(), strFilter[0].end(), strFilter[0].begin(), ::toupper);
	transform(strFilter[1].begin(), strFilter[1].end(), strFilter[1].begin(), ::toupper);


	for (int i = 0;i < DATA_SIZE;i++)
	{
		//local copy of state name
		string strState = Cities[i].State;
		transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		//match of either filter
		if ((strFilter[0] == strState) ||
			(strFilter[1] == strState))
		{
			printf("%s,%s,%d\n",
				Cities[i].City.c_str(),
				Cities[i].State.c_str(),
				Cities[i].Population);
		}
	}
}
//displays two sets of data
void OR(CitiesStruct Cities[])
{
	string strFilter[2];		//user input

	printf("Please enter the name of a US State: ");
	getline(cin, strFilter[0]);//get user input
	printf("Please enter the name of another US State: ");
	getline(cin, strFilter[1]);//get user input

							   //uppercase the user input
	transform(strFilter[0].begin(), strFilter[0].end(), strFilter[0].begin(), ::toupper);
	transform(strFilter[1].begin(), strFilter[1].end(), strFilter[1].begin(), ::toupper);

	//output 2nd state data
	for (int i = 0;i < DATA_SIZE;i++)
	{
		//local copy of state name
		string strState = Cities[i].State;
		transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		//match 1st state
		if (strFilter[0] == strState)
		{
			printf("%s,%s,%d\n",
				Cities[i].City.c_str(),
				Cities[i].State.c_str(),
				Cities[i].Population);
		}
	}
	cout << endl << endl;//blank line

	//output 2nd state data
	for (int i = 0;i < DATA_SIZE;i++)
	{
		//local copy of state name
		string strState = Cities[i].State;
		transform(strState.begin(), strState.end(), strState.begin(), ::toupper);

		//match 1st state
		if (strFilter[1] == strState)
		{
			printf("%s,%s,%d\n",
				Cities[i].City.c_str(),
				Cities[i].State.c_str(),
				Cities[i].Population);
		}
	}
}
void XOR(CitiesStruct Cities[])
{
	string strFilter;		//user input
	CitiesStruct foundCity;	//data from match
	int iFound = 0;			//has this city been found?


	printf("Please enter the name of a City: ");
	getline(cin, strFilter);//get user input

							//uppercase the user input
	transform(strFilter.begin(), strFilter.end(), strFilter.begin(), ::toupper);

	for (int i = 0;i < DATA_SIZE;i++)
	{
		//local copy of city name
		string strCity = Cities[i].City;
		transform(strCity.begin(), strCity.end(), strCity.begin(), ::toupper);

		//match 1st state
		if (strFilter == strCity)
		{
							//store data in local struct
			foundCity.State = Cities[i].State;
			foundCity.City = Cities[i].City;
			foundCity.Population = Cities[i].Population;
			iFound++;		//increment found counter
		}
	}
	if (iFound == 1)			//XOR, only found one match
	{
		printf("%s,%s,%d\n",
			foundCity.State.c_str(),
			foundCity.City.c_str(),
			foundCity.Population);
	}
	else if (iFound > 1)
		printf("Found %s multiple times\n", foundCity.City.c_str());

}
void RANGE(CitiesStruct Cities[])
{								//copy of found cities
	CitiesStruct localCities[DATA_SIZE];
	int iIndex=0;					//index of localCities

	for(int i=0;i<DATA_SIZE;i++)//loop thrugh main array
								//greater than 1 million and less thN 2.5 Million
		if ((Cities[i].Population > 1000000) &&
			(Cities[i].Population < 3000000))
		{
			//copy array element to local array
			localCities[iIndex].City = Cities[i].City;
			localCities[iIndex].State = Cities[i].State;
			localCities[iIndex].Population = Cities[i].Population;
			iIndex++;			//increment index
		}
//sort(localCities[0],localCities[iIndex]);
//TODO: sort the temp list
//

	//display
	for (int i = 0;i < iIndex;i++)
	{
		printf("%d: %s,%s,%d\n", 
			i+1,
			localCities[i].City.c_str(),
			localCities[i].State.c_str(),
			localCities[i].Population);
	}
}

int main()
{
								//array from data file
	CitiesStruct Cities[DATA_SIZE];	

	if (LoadFile(Cities))
	{
		//Subset(Cities);		//get subset of array
		//NOT(Cities);			//get NOT subset of array
		//AND(Cities);			//get AND(2states) subset of arrray
		//OR(Cities);			//get one or the other state
		//XOR(Cities);			//exclusive or(XOR)
		RANGE(Cities);			//display a pop range
	}

	cout << endl << endl;	//blank line
	system("Pause");		//pause before closing
    return 0;
}

