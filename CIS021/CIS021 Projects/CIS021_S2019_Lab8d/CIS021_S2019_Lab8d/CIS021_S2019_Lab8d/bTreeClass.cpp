// Project:		CIS021_S2019_Lab8d
// Module:		bTreeClass.cpp
// Author:		Mark Berrett
// Date:		April 16, 2019
// Purpose:		Implimentation file for bTreeClass
//

#include "stdafx.h"
#include "bTreeClass.h"

// constructor
bTreeClass::bTreeClass()
{
}

// destructor
bTreeClass::~bTreeClass()
{
	// delete leaves to prevent memory leaks
	LeafClass* tempNode = new LeafClass;
	LeafClass* prevNode = new LeafClass;
	int MoveDirection;

	while (rootNode != nullptr) // repeat until entire tree is empty
	{
		tempNode = rootNode;
		while (tempNode != nullptr)	// repeat until a leaf is deleted
		{
			if (tempNode->GetLeftLink() != nullptr)			// if there's a link to the left
			{
				prevNode = tempNode;					// keep track of previous leaf
				tempNode = tempNode->GetLeftLink();		// move to next left link
				MoveDirection = -1;						// this was a left move
			}
			else if (tempNode->GetRightLink() != nullptr)	// no left? is there one on the right
			{
				prevNode = tempNode;					// keep track of previous leaf
				tempNode = tempNode->GetRightLink();	// move to next right leaf
				MoveDirection = 1;						// this was not a left move
			}
			else	// no left or right, this is the last leaf in this thread, delete it
			{
				if (MoveDirection == -1)				// if the last move was left
					prevNode->SetLeftLink(nullptr);			// previous leaf's left is null
				else if (MoveDirection == 1)			// else previous move was right
					prevNode->SetRightLink(nullptr);		// prevous leaf's right is null

				if (tempNode == rootNode)				// if this is the root leaf
					rootNode = nullptr;					//	delete it too

				delete tempNode;						// delete this leaf
				tempNode = nullptr;						// set it to null so the loop stops
			}
		}
	}
}

// using input string, create a new leaf and insert it in the correct position in the binary tree
void bTreeClass::Insert(char cIn, string strIn)
{
	LeafClass* newLeaf = new LeafClass;	// new node to be inserted into tree as a leaf
	LeafClass *tempNode;				// temp node for comparison
	bool done = false;					// true after new Leaf inserted into tree

	newLeaf->SetData(cIn, strIn);		// store the data

	newLeaf->SetLeftLink(nullptr);		// initialize the pointers
	newLeaf->SetRightLink(nullptr);

	if (rootNode == nullptr) // if this is the top of the file, build the root Leaf
	{
		rootNode = newLeaf;
	}
	else // add to the list
	{
		tempNode = rootNode; // start at the root

		while (!done) // traverse until we find the right spot to append the new leaf
		{
			// compare new Leaf with loop Leaf
			if (MCompare(newLeaf->GetCode(), tempNode->GetCode()) < 0) // if new < temp, go left
			{
				if (tempNode->GetLeftLink() == nullptr) // if left is empty
				{
					tempNode->SetLeftLink(newLeaf);		// then create leaf
					done = true;
				}
				else
					tempNode = tempNode->GetLeftLink(); // else move down a level

			}
			else // greater than, go right
			{
				if (tempNode->GetRightLink() == nullptr) // if right is empty
				{
					tempNode->SetRightLink(newLeaf); // then create leaf
					done = true;
				}
				else
					tempNode = tempNode->GetRightLink(); // else move down a level
			}
		}
	}
}

// search the binary tree for a specific code string, return the letter/number
// returns space ' ' if paramanter not a Morse code sequence
char bTreeClass::Search(string strSearch)
{
	LeafClass * tempNode = rootNode;					// start search at root node
	cReturn = ' ';										// if not found, return space

	// before any searching, make sure the search string does not contain anything but dahs and dits
	for (int i = 0; i < strSearch.length(); i++)
		if (strSearch[i] != '-' && strSearch[i] != '.')
			return cReturn;

	// make sure a root was built before the 1st traverse is attempted
	if (rootNode == nullptr)
		return cReturn;

	for (int iIndex = 0; iIndex < strSearch.length(); iIndex++)
	{
		if (strSearch[iIndex] == '-')					// -  moves to left
			tempNode = tempNode->GetLeftLink();
		if (strSearch[iIndex] == '.')					// . goes to right
			tempNode = tempNode->GetRightLink();

		if (tempNode == nullptr)						// jump out if ran off the end of tree
			break;
	}

	if (tempNode != nullptr)							// if a valid leaf was found
		cReturn = tempNode->GetLetter();

	return cReturn;										// return search result
}


// looks at 2 Morse codes strings
// returns -1 if str1 < str2 (dah)
//			0 if something went wrong
//			1 if str1 > str2 (dit)
int bTreeClass::MCompare(string str1, string str2)
{
	int iReturn = 0;									// return value
	int iIndex = 0;										// searching through strings

	if (str2 == " ")									// check for root node
		if (str1[0] == '-')
			return -1;									// dah to the left
		else
			return 1;									// dit to the right

	while (iIndex < str1.length())
	{
		if (iIndex >= str2.length())					// ran out of second string
		{
			if (str1[iIndex] == '-')
				return -1;								// dah to the left
			else
				return 1;								// dit to the right
		}
		
		iIndex++;										// = so far, go to next char in strings
	}
	
	return iReturn;										// return value
}
