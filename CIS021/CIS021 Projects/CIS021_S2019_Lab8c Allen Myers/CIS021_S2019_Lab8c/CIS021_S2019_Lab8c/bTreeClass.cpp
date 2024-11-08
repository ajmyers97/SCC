// Project:		CIS021_S2019_Lab8c
// Module:		bTreeClass.cpp
// Aurthor:		Mark Berrett
// Date:		April 14, 2019
// Purpose:		Implimentation file for bTreeClass
//

#include "stdafx.h"
#include "bTreeClass.h"


bTreeClass::bTreeClass()
{
}


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
void bTreeClass::Insert(string strIn)
{
	LeafClass* newLeaf = new LeafClass;	// new node to be inserted into tree as a leaf
	LeafClass *tempNode;				// temp node for comparison
	bool done = false;					// true after new Leaf inserted into tree

	newLeaf->SetString(strIn);			// store the data

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
			if (newLeaf->GetString().compare(tempNode->GetString()) < 0) // if new < temp, go left
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

// search the binary tree for a specific string
string bTreeClass::Search(string strSearch)
{
	LeafClass * tempNode;								// current node in existing btree
	string strNodeData;									// string from current node
	bool bDone = false;									// true with string found

														// make sure a root was built before the 1st traverse is attempted
	if (rootNode == nullptr)
		bDone = true;

	strReturn = "Search path: ";
	tempNode = rootNode;

	while (!bDone)										// loop until string found, or end of tree
	{
		strNodeData = tempNode->GetString();			// node data for comparison to strSearch

		if (strSearch == strNodeData)					// found?
		{
			strReturn += "\nName: " + strNodeData;			// return found data
			bDone = true;								// finish while loop
		} // is =
		else if (strSearch < strNodeData)				// less than, go left
		{
			if (tempNode->GetLeftLink() == nullptr)		// if no link on the left
			{
				strReturn += "\n<string not found>";	// indicate not found
				bDone = true;							// finish while loop
			}
			else
			{
				tempNode = tempNode->GetLeftLink();		// move down a level, to the left
				strReturn += "<";						// traverse indicator
			}
		} // is <
		else // must be >
		{
			if (tempNode->GetRightLink() == nullptr)	// if no link on the right
			{
				strReturn += "\n<string not found>";	// indicate not found
				bDone = true;							// finish while loop
			}
			else
			{
				tempNode = tempNode->GetRightLink();	// move down a level, to the right
				strReturn += ">";						// traverse indicator
			}

		} // is >
	} // while !bDone

	return strReturn;									// return search result
}
