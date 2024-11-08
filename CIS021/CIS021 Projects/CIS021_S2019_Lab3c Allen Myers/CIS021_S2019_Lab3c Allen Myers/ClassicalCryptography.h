//Project:	CIS021_S2019_Lab3c Allen Myers
//Module:	CIS021_S2019_Lab3c Allen Myers.cpp
//Author:	Allen Myers
//Date:		Feb 12th, 2019
//Purpose:	Header file for Crypto
#pragma once
class ClassicalCryptography
{
public:
	ClassicalCryptography();
	~ClassicalCryptography();

	std::string Caesar(std::string, int);		//encrypt
	std::string DeCaesar(std::string, int);		//decrypt
	std::string Replacement(std::string);		//replacement cipher
	std::string UnReplacement(std::string);				//decipher from replacement
private:
	std::string strReturn;						//return string
	char Cipher[128];							//replacement cipher loaded from file
	bool LoadFile();							//load the cipher file

};

