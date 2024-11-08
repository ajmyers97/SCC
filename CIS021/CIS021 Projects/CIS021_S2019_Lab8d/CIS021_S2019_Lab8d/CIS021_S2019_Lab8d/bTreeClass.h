// Project:		CIS021_S2019_Lab8d
// Module:		bTreeClass.h
// Author:		Mark Berrett
// Date:		April 16, 2019
// Purpose:		Header file for bTreeClass.cpp
//				B-Tree implementation
//

#pragma once
class bTreeClass
{
public:
	bTreeClass();
	~bTreeClass();					// deletes all nodes to prevent a memory leak

	void Insert(char, string);		// inserts a new leaf in the correct position
	char Search(string);			// search for a string in the tree

private:

	LeafClass* rootNode;		// pointer to root node

	char cReturn;					// return value for Search(), letter
	string strReturn;				// return value for Search(), code

	int MCompare(string, string);	// for Mose code -1 if 1st < 2nd, 0 if =, 1 if 1st > 2nd
};

