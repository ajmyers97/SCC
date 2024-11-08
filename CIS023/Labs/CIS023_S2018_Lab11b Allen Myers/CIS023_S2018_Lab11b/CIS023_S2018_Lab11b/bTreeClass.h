//Module:	bTreeClass.h
//Project:	CIS023_S2018_Lab11b
//Author:	Allen Myers
//Date:		April 25th, 2018
//Purpose:	Traverse a binary tree.

#pragma once
class bTreeClass
{
public:
	bTreeClass();
	~bTreeClass();				// deletes all nodes to prevent a memory leak

	void Insert(string);		// inserts a new leaf in the correct position
	string Search(string);		// search for a string in the tree

private:

	NodeClass* rootNode;		// pointer to root node
	string strReturn;			//return string from Search();
};

