//Module:	bTreeClass.cpp
//Project:	CIS023_S2018_Lab11a
//Author:	Allen Myers	
//Date:		April 23rd, 2018
//Purpose:	Implementation File for bTreeClass.cpp
//			Binary Tree
//	
#include "stdafx.h"
#include "bTreeClass.h"


bTreeClass::bTreeClass()
{
}

//destructor, delete all nodes to prevent memory leaks
bTreeClass::~bTreeClass()
{
	//delete the tree
	NodeClass*tempNode = nullptr;		//current node
	NodeClass*prevNode = nullptr;						//previous node, for comparison
	int MoveDirection;									// -1 is left or 1 is right
	bool bDelete = false;								//did this loop delete a node?

	while (rootNode != nullptr)							//loop until all nodes deleted
	{
		tempNode = rootNode;							//start at the root node
		MoveDirection = 0;								//reset direction
		bDelete = false;								//loop until a node it deleted
		do {
			if (tempNode->GetLeftLink() != nullptr)			//if there is a node to the left
			{
				prevNode = tempNode;						//keep track of previous node
				MoveDirection = -1;							//moved to the left
				tempNode = tempNode->GetLeftLink();			//then go there
			}

			else if (tempNode->GetRightLink() != nullptr)	//if there is a node to the right
			{
				prevNode = tempNode;						//keep track of previous node
				MoveDirection = 1;							//moved to the right
				tempNode = tempNode->GetRightLink();		//then go there
			}
			else
			{
				if (MoveDirection ==-1)						//was the last move to the left?
					prevNode->SetLeftLink(nullptr);			//delete the pointer to the left
				else
					prevNode->SetRightLink(nullptr);		//else delete the node to the right
				if (tempNode == rootNode)						//if this is the root node
					rootNode = nullptr;						//so the loop knows to stop
				delete tempNode;							//then delete it
				bDelete = true;								//set flag
			}
		} while (!bDelete);									//traverse until a node is deleted
	}
}
//using input string, create a new leaf and insert it in the correct position
//in the binary tree
void bTreeClass::Insert(string strIn)
{
	NodeClass*newLeaf = new NodeClass;						//new node to be inserted into tree as leaf
	NodeClass*tempNode;										//tempnode for comparison
	bool bDon = false;										//true after new leaf inserted into tree

	newLeaf->SetString(strIn);								//store the data
	newLeaf->SetLeftLink(nullptr);							//initialize the pointer
	newLeaf->SetRightLink(nullptr);

	if (rootNode == nullptr)								//if this is the 1st node, butild the root leaf
	{
		rootNode = newLeaf;						
	}
	else
	{
		tempNode = rootNode;								//start the tempnode at root node

		while (!bDon)										//traverse the tree until we find the right spot
		{
			//compare new leaf with loop leaf, only works if data is assumed to be good
			if (strIn.compare(tempNode->GetString()) < 0)	//if new<current, go left
			{
				if (tempNode->GetLeftLink() == nullptr)		//if left is empty
				{
					tempNode->SetLeftLink(newLeaf);			//create the leaf
					bDon = true;							//leaf inserted, done
				}
				else
					tempNode = tempNode->GetLeftLink();		//else move down a level


			}//if
			else											//new>current, go right
			{
				if (tempNode->GetRightLink() == nullptr)		//if left is empty
				{
					tempNode->SetRightLink(newLeaf);			//create the leaf
					bDon = true;							//leaf inserted, done
				}
				else
					tempNode = tempNode->GetRightLink();		//else move down a level										
			}//else move right
		}//while(!bDdone)
	}//else not first node
}//Insert()
