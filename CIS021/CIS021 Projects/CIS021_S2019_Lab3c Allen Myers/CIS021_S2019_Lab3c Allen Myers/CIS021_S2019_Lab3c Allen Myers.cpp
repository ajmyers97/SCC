//Project:	CIS021_S2019_Lab3c Allen Myers
//Module:	CIS021_S2019_Lab3c Allen Myers.cpp
//Author:	Allen Myers
//Date:		Feb 12th, 2019
//Purpose:	Review class creation.
//			Perform operations on a template class.
//			Learn how to convert algorithms into virtual functions.

#include "stdafx.h"

int main()
{
	string strInput;							//user input
	string strEncrypted;						//user input encrypted
	string strDecrypted;						//encrypted string decrypted
	ClassicalCryptography cc;					//encryption object

	cout << "Julius Caeser's Cipher" << endl << endl;
	cout << "F(P)=(P+K) mod 26" << endl << endl;

	//get the user input from the console
	cout << "Enter a string to encrypt: ";
	getline(cin, strInput);
	strEncrypted = cc.Caesar(strInput, 3);			//encrypt user data

	//display results
	cout << "Encrypted: " <<
		strEncrypted << endl;

	//decrypt the encrypted string
	strDecrypted = cc.DeCaesar(strEncrypted, -3);	//the three helps with encrypting and decrypting
	cout << "Decrypted: " <<
		strDecrypted << endl << endl;

	cout << "Replacement Cipher" << endl << endl;

	//encrypt using the replacement method
	strEncrypted = cc.Replacement(strInput);
	//display the encrypted file
	cout << "Encrypted: " << strEncrypted << endl;

	//decrypt
	strDecrypted = cc.UnReplacement(strEncrypted);
	cout << "Decrypted: " << strDecrypted << endl;






	cout << endl << endl;						//blank line
	system("Pause");							//pause before closing
    return 0;
}

