//Module:	StateInfo.h
//Project:	CIS023_S2018_HW8 Allen Myers
//Author:	Allen Myers
//Date:		March 28th, 2018
//Purpose:	Load a file into a linked list.
//			Traverse the linked list in both directions.
//
#pragma once
class StateInfo
{
public:
	StateInfo();
	~StateInfo();
	StateInfo(string, string, string, string, string, string);		//overloaded constructor

	TCHAR *GetState();											//return values
	TCHAR *GetCapitol();
	TCHAR*GetNickname();
	TCHAR *GetBird();
	TCHAR *GetFlower();
	TCHAR *GetTree();

	void SetPrev(StateInfo*);								//set previous node
	void SetNext(StateInfo*);								//set next node
	StateInfo*GetPrev();									//return prev node
	StateInfo*GetNext();									//return next node
private:
	TCHAR szState[TCHAR_SIZE];									//stored values
	TCHAR szCapitol[TCHAR_SIZE];
	TCHAR szBird[TCHAR_SIZE];
	TCHAR szFlower[TCHAR_SIZE];
	TCHAR szTree[TCHAR_SIZE];
	TCHAR szNickname[TCHAR_SIZE];

	StateInfo*prevNode;									//pointer to prev node
	StateInfo*nextNode;									//pointer to next node




};

