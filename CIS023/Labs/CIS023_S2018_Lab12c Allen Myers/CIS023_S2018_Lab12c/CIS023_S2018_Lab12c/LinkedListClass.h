//Module:	LinkedListClass.h
//Project:	CIS023_S2018_Lab12c
//Author:	Allen Myers
//Date:		May 7th, 2018
//Purpose:	List of stars.
//
#pragma once
class LinkedListClass
{
public:
	LinkedListClass();
	~LinkedListClass();

	void Add(HWND);						// append a start to the list
	void Delete();						// delete the currentStar
	void First();						// make currentStar the 1st star in the list
	void Next();						// advance currentStar to next star in list

	StarClass* GetFirstStar();			//return pointer to first star object
	StarClass* GetCurrentStar();		//return pointer to current star
	void SetCurrentStar(StarClass*);	//set current star pointer

private:
	StarClass* firstStar;				// first node in list
	StarClass* lastStar;				// last node in list
	StarClass* currentStar;				// current node

};

