//Module:	CIS021_S2019_Lab8c.cpp
//Program:	CIS021_S2019_Lab8c
//Author:	Allen Myers
//Date:		May 7th, 2019
//Purpose:	Understand how binary trees store and retrieve data.
//			Explore Huffman's Algorithm.
//			Compare B - Tree load and search times to arrays, linked lists, and vectors.
//
#include "stdafx.h"

// constants
#define ARRAY 0
#define LIST 1
#define BTREE 2
#define VECTOR 3

// global variables
char szFileName[] = "50000 names.txt";			// file that contains data for binary tree

string strArray[50000];							// string array
LinkedListClass* list = nullptr;				// linked list
bTreeClass* bTree = nullptr;					// binary tree
vector <string> vList;							// vector

//Search strArray[]
void SearchArray(string strIn)
{
	for (int i = 0;i <50000 ;i++)				//search array
	{
		if (strArray[i] == strIn)					//match found
		{
			printf("%5d. %s\n", i, strArray[i].c_str());	//display
			break;								//found, no need to continue 
		}
	}
}

//Search Linked List
void SearchList(string strIn)
{
	string strNodeData;							//data from node
	int iLineNo = 0;							//node count

	list->SetCurrentNode(list->GetFirstNode());	//start at first node

	while (list->GetCurrentNode() !=nullptr)		//loop until end of list
	{
		//get data from current node
		strNodeData = list->GetCurrentNode()->GetString();
		iLineNo++;									//count
		if (strNodeData == strIn)					//found
		{
			printf("%5d. %s\n", iLineNo, strIn.c_str());	//display
			break;								//found, no need to continue 
		}
		//advance to next node
		list->SetCurrentNode(list->GetCurrentNode()->GetNextNode());
	}

}

//Search B-Tree
void SearchbTree(string strIn)
{
	//use the Search() method in bTreeClass.cpp to find the search string
	string strReturn = bTree->Search(strIn);

	printf("%s\n",strIn.c_str());				//display string


}

//search the vector
void SearchVector(string strIn)
{
	////slower method
	//for (int i = 0;i <50000;i++)				//search array
	//{
	//	string strList=vList.at(i);							//jump to indexed element
	//	if (strList == strIn)					//match found
	//	{
	//		printf("%5d. %s\n", i, strArray[i].c_str());	//display
	//		break;								//found, no need to continue 
	//	}
	//}

	//faster method
	for (auto strSearch : vList)
	{
		if (strIn == strSearch)
		{
			printf("%s\n", strIn.c_str());				//display string
			break;
		}
	}
}

// Either show the time in milliseconds, or show the elapsed time between start and end
void ShowTime(SYSTEMTIME &sysStartTime, bool bStart)
{
	if (bStart)									// if this is the start time
	{
		GetSystemTime(&sysStartTime);
		printf("Start: %d:%d.%d  ", sysStartTime.wMinute, sysStartTime.wSecond, sysStartTime.wMilliseconds);
	}
	else										// display end time and calculate gap
	{
		SYSTEMTIME sysEndTime;

		GetSystemTime(&sysEndTime);
		printf("End: %d:%d.%d  ", sysEndTime.wMinute, sysEndTime.wSecond, sysEndTime.wMilliseconds);

		// calculate interval between times
		SYSTEMTIME sysElapse;
		FILETIME v_ftime;
		ULARGE_INTEGER v_ui;
		__int64 v_right, v_left, v_res;
		SystemTimeToFileTime(&sysEndTime, &v_ftime);
		v_ui.LowPart = v_ftime.dwLowDateTime;
		v_ui.HighPart = v_ftime.dwHighDateTime;
		v_right = v_ui.QuadPart;

		SystemTimeToFileTime(&sysStartTime, &v_ftime);
		v_ui.LowPart = v_ftime.dwLowDateTime;
		v_ui.HighPart = v_ftime.dwHighDateTime;
		v_left = v_ui.QuadPart;

		v_res = v_right - v_left;

		v_ui.QuadPart = v_res;
		v_ftime.dwLowDateTime = v_ui.LowPart;
		v_ftime.dwHighDateTime = v_ui.HighPart;
		FileTimeToSystemTime(&v_ftime, &sysElapse);

		printf("Elapsed time: %02d:%02d.%03d\n", sysElapse.wMinute, sysElapse.wSecond, sysElapse.wMilliseconds);

	}

}


// read the file and load the binary tree
bool LoadFile(int iDest)
{
	ifstream inFile;						// file handle
	string strLine;							// a line in the file
	SYSTEMTIME sysTime;						// for calculating time to perform action
	int iIndex = 0;							// used by array

	ShowTime(sysTime, true);				// get and display start time

	try
	{
		inFile.open(szFileName);			// open the file

		if (!inFile.is_open())
			throw 0;

		if (list == nullptr)
			list = new LinkedListClass;		// create linked list

		if (bTree == nullptr)
			bTree = new bTreeClass;			// create the binary tree
		
		getline(inFile, strLine);
		while (inFile.good())				// if more to read
		{
			switch (iDest)
			{
			case ARRAY:
				strArray[iIndex++] = strLine;	//load string into array
				break;
			case LIST:
				list->Add(strLine);				//add a node to the end of the linked list
				break;
			case BTREE:
				bTree->Insert(strLine);			//add a leaf to the bTree
				break;
			case VECTOR:
				vList.push_back(strLine);		//append string to vector list
				break;
			default:
				break;						// default used to open and read file without loading (pre-fetch)
			}
			getline(inFile, strLine);		// get the next line from the file
		}

		inFile.close();						// close the file

		ShowTime(sysTime, false);			// display end time and end - start time
		cout << endl;

	}
	catch (int)
	{
		printf("Failed to open data file.\n\n");
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////
int main()
{
	// search strings
	string strSearch[] = { "ADAIR, XAVIER", "MELO, HUGH", "STILES, SOCORRO", "SNELL, ETHAN", "BOYD, BUD", "WIESE, SANDY" };

	SYSTEMTIME sysTime;						// for calculating time to perform action
	string strString;

	printf("Demonstrate the Efficiencies of Lists\n\n");		// title
	////////////////////////////////Pre-Load
	printf("Pre-load\n");
	LoadFile(NULL);

	///////////////////////////////Array
	printf("************Loading Array************\n");
	if (LoadFile(ARRAY))
	{
		ShowTime(sysTime, true);			//show start time of search
		cout << endl;

		for (int i = 0;i < 6;i++)			//search for 6 names
			SearchArray(strSearch[i]);

		ShowTime(sysTime, false);			//show elapsed time
	}
	//////////////////////////////Linked List
	printf("************Loading Unsorted Linked List************\n");
	if (LoadFile(LIST))						//load the linked list
	{
		ShowTime(sysTime, true);			//show start time of search
		cout << endl;

		for (int i = 0;i < 6;i++)			//search for 6 names
			SearchList(strSearch[i]);

		ShowTime(sysTime, false);			//show elapsed time

	}
	//////////////////////////////b-tree
	printf("************Loading b-Tree************\n");
	if (LoadFile(BTREE))						//load the b-Tree
	{
		ShowTime(sysTime, true);			//show start time of search
		cout << endl;

		for (int i = 0;i < 6;i++)			//search for 6 names
			SearchbTree(strSearch[i]);

		ShowTime(sysTime, false);			//show elapsed time

	}
	/////////////////////////////Vectors
	printf("************Loading Vectors************\n");

	if (LoadFile(VECTOR))						//load the b-Tree
	{
		ShowTime(sysTime, true);			//show start time of search
		cout << endl;

		for (int i = 0;i < 6;i++)			//search for 6 names
			SearchVector(strSearch[i]);

		ShowTime(sysTime, false);			//show elapsed time

	}

	cout << endl << endl;					// blank line
	system("Pause");						// pause befroe closing
	return 0;
}

