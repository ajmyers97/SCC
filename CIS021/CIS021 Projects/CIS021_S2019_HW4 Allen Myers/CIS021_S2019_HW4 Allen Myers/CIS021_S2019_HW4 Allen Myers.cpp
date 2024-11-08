//Project:		CIS021_S2019_HW4 Allen Myers
//Module:		CIS021_S2019_HW4 Allen Myers.cpp
//Author:		Allen Myers
//Date:			March 8th, 2019
//Purpose:		Demonstrate recursion.
//				Review creation of recursive functions.
//				Solve a complex problem.
//

#include "stdafx.h"

//read in the values from each coordinate in the array(a,b,c,d)
//store as a string
//call the recursive function for the loop with the (N,S,E,W) values
void ConvertArrayValsToString(int iArrayVal[])
{
	int iIndex = 0;											//initialize iIndex to 0
	string strIn;											//indexed array
	int nVal, sVal, eVal, wVal;								//values from the array, at [2][2]=(0, 1, 0, 1)

	iArrayVal[iIndex++] = stoi(strIn.c_str());				//convert to int, store array
	

	RecursiveGridPath(nVal, sVal, eVal, wVal);					//call the recursive function

}
//compare the array values against the pre-determined values for (N,S,E,W)
//if these values are equal, you can go through the door.
//if not equal, you must look at the next door
void RecursiveGridPath(int nVal, int sVal, int eVal, int wVal)	//the values from the array
{
	int NorthDirection = 0;										//direction values for output
	int SouthDirection = 1;
	int EastDirection = 2;
	int WestDirection = 3;

	for (int i = 0; i < 4; i++)								//itterate through the array
		//compare the values for each block against the values for (N,S,E,W) from the array
		if (nVal == NorthDirection)
			nVal== NorthDirection;
			//go through that door
		else if (sVal==SouthDirection)
		{
			//append the list to show the value


		}
		else if (eVal==EastDirection)
		{
			//append the list to show the value


		}
		else if (wVal==WestDirection)
		{
			//append the list to show the value

		}
		else()
		

		

		
}


int main()
{
	cout << "--Grid of Recursion--" << endl;					//title

	string pathValue;											//string value of the path traveled

	int Array[5][5]											//array data
		= {(1, 0, 1, 0), (0, 0, 1, 1),(0, 0, 1, 1),(0, 1, 0, 1),(0, 0, 1, 0),
		   (0, 1, 0, 0),(0, 0, 1, 0),(0, 0, 1, 1),(1, 0, 1, 1),(0, 1, 0, 1),
		   (1, 1, 0, 0),(0, 0, 1, 0),(0, 1, 0, 1),(0, 1, 1, 0),(1, 1, 0, 1),
		   (1, 0, 1, 0),(0, 1, 1, 1),(1, 1, 1, 1),(1, 0, 0, 1),(1, 0, 0, 0),
		   (0, 1, 0, 0),(1, 0, 1, 0),(0, 0, 1, 1),(0, 0, 0, 1),(0, 0, 1, 0)};

	ConvertArrayValsToString(Array[2][2]);								//start at [2][2]=(0, 1, 0, 1)
	printf("The path of travel is: %d\n", pathValue);			//display the path traveled

	cout << endl << endl;										//blank line
	system("Pause");											//pause before closing
    return 0;
}

