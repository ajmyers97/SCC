// Project: CIS021_S2019_Lab3d Stephen Ackerman
// Module:  CIS021_S2019_Lab3d Stephen Ackerman.cpp
// Date:    Feb 14, 2019
// Author:  Stephen Ackerman
// Appended on 2/19/2019 by Allen Myers
// Purpose: Review creation of class header and implementation files.
//			Review coding a formula into a algorithm.
//			Produce computer code that encrypts and decrypts data.

#include "stdafx.h"


int main()
{
	RSACryptosystem RSA;
	std::string strInput;		// user input
	_int64 _intEncrypted[100];	//user input after encryotion
	std::string strDecrypted;		//decrypted string
	int iIndex = 0;				//index into _intEncrypted[]


	printf("Enter a string to encrypt: ");
	std::getline(std::cin, strInput);			// get user input

	RSA.Encrypt(strInput, _intEncrypted);		//call encryption 

	//at this point, _intEncrypted has out input string stored as an array
	//of large integers. We would most likely store, or use it in some
	//other fashion at this point.

	//display all elements of encrypted array
	while (_intEncrypted[iIndex] != 0)						//display until blank
		std::cout << _intEncrypted[iIndex++] << "";

	std::cout << std::endl;									//end line
			
	std::cout << "Decrypted string: " << std::endl;

	//decrypt the array
	strDecrypted = RSA.Decrypt(_intEncrypted);
	std::cout << strDecrypted << std::endl;;				//display decrypted string


	

	std::cout << std::endl << std::endl;					// blank line
	system("Pause");										// pause before closing
    return 0;
}

