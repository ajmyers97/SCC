//Project:	CIS021_S2019_Lab3c Allen Myers
//Module:	CIS021_S2019_Lab3c Allen Myers.cpp
//Author:	Allen Myers
//Date:		Feb 12th, 2019
//Purpose:	Implementation file for crypto
#include "stdafx.h"
#include "ClassicalCryptography.h"


ClassicalCryptography::ClassicalCryptography()
{
}


ClassicalCryptography::~ClassicalCryptography()
{
}

std::string ClassicalCryptography::DeCaesar(string strIn, int iRoll)
{
	strReturn = "";							//clear return string
	for (int i = 0; i < strIn.length(); i++)
	{
		if (strIn[i] == 0x20)				//space
			strReturn += ' ';
		else if (strIn[i] + 3 > 0x7E)		//end of alphabet
			strReturn += strIn[i] + 3 - 0x5E;
		else								//all other chars
			strReturn += strIn[i] + 3;
	}

	return string();						//return decrypted string
}

std::string ClassicalCryptography::Replacement(string strIn)
{
	strReturn = "";								//clear return string
	if (LoadFile())								//load the cipher
	{
		for (int i = 0; i < strIn.length(); i++)		//roll through the string
			strReturn +=							//encrypt
			Cipher[strIn[i]];
	}
	return std::string();
}

std::string ClassicalCryptography::UnReplacement(string strIn)
{
	strReturn = "";								//initialize return string
	char cIndex;								//loop through cipher


	for (int i = 0; i < strIn.length(); i++)	//roll through the string
	{
		for (cIndex = 0; cIndex < 128; cIndex++)		//roll through cipher array
			if (strIn[i] == Cipher[cIndex])				//found matching value
			{
				strReturn +=							//decrypt
				cIndex;
				break;
			}
	}

	return string();
}

bool ClassicalCryptography::LoadFile()
{
	ifstream inFile;							//handle to cipher file
	string strPath =							//file name
		"cipher.txt";
	string strIn;									//file input
	int iIndex = 0;								//index into cipher array
	inFile.open(strPath);						//open the file
	if (inFile.is_open())						//did the file open?
	{
		getline(inFile, strIn);					//get the first line frome the file
		while (inFile.good())					//until EOF
		{
			Cipher[iIndex++] =					//insert into array
				stoi(strIn.c_str());
			getline(inFile, strIn);				//get next line
		}

		inFile.close();							//close thr file
		return true;
	}
	return false;
}

std::string ClassicalCryptography::Caesar(string strIn, int iRoll)
{
	char c;									//1 char at a time
	strReturn = "";							//clear return string
	for (int i = 0; i < strIn.length(); i++)
	{
		c = strIn[i];						//get current char

		if (c == 0x20)						//do not roll if a space
			strReturn += 0x20;
		else
		{
			c = c + iRoll;					//roll as per specs

			char cNow = (c - 0x7E);
			cNow = 0x1F + cNow;

			if (c > 0x7E)					//if rolled past alphabet
				c = 0x20;					//rolled to space
			if (c < 0x20)				//if rolled past start of alphabet
				c = 0x7F - (0x20 - c);		//that many before end
			strReturn += c;					//add to the return string
		}


		//if (c >= 0x20 && c <= 0x7E)		//only work with reg chars
		//switch (c)						//convert char
		//{
		//case 0x20:						//space
		//	strReturn += ' ';				//dont convert space
		//	break;
		//case 0x7C:						//roll the last 43 chars
		//	strReturn += 0x21;
		//	break;
		//case 0x7D:						//roll the last 3 hars
		//	strReturn += +0x22;
		//	break;
		//case 0x7E:						//all other chars
		//	strReturn += 0x23;
		//	break;
		//default:
		//	strReturn += c + iRoll;		//roll based on the definition
	}
	return string();
}
