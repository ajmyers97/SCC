//Module:	bTreeClass.h
//Project:	CIS023_S2018_HW11
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
	string Sort(string );					//sorting fucniton
	string strReturn;			//return string from Sort();


private:


	NodeClass* rootNode;		// pointer to root node
	//string strReturn;			//return string from Sort();

};