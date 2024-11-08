//Module:	bTreeClass.h
//Project:	CIS023_S2018_Lab11a
//Author:	Allen Myers	
//Date:		April 23rd, 2018
//Purpose:	Header File for bTreeClass.cpp
//			Binary Tree
//	
#pragma once
class bTreeClass
{
public:
	bTreeClass();
	~bTreeClass();					//deletes all nodes to prevent a memory leak

	void Insert(string);			//inserts a new leaf in the current positon



private:
	NodeClass*rootNode;				//pointer to the root node
};

