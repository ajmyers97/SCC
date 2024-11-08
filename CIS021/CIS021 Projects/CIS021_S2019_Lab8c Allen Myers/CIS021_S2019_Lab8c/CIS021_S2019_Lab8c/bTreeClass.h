// Project:		CIS021_S2018_Lab8c
// Module:		bTreeClass.h
// Aurthor:		Mark Berrett
// Date:		April 14, 2019
// Purpose:		Header file for bTreeClass.cpp
//				B-Tree implementation
//

#pragma once
class bTreeClass
{
public:
	bTreeClass();
	~bTreeClass();				// deletes all nodes to prevent a memory leak

	void Insert(string);		// inserts a new leaf in the correct position
	string Search(string);		// search for a string in the tree

private:

	LeafClass* rootNode;		// pointer to root node

	string strReturn;			// return value for Search()
};

