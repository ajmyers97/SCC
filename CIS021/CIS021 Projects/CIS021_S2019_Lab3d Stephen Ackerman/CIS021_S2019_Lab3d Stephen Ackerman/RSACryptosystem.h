// Project: CIS021_S2019_Lab3d Stephen Ackerman
// Module:  RSACryptosystem.h
// Date:    Feb 14, 2019
// Appended on 2/19/2019 by Allen Myers
// Author:  Stephen Ackerman
// Purpose: Header file for RSACryptosystem.cpp
//			RSA encryption and decryption

#pragma once
class RSACryptosystem
{
public:
	RSACryptosystem();				// default constructor
	~RSACryptosystem();

	void Encrypt(std::string, _int64[]);		// encrypt string
	std::string Decrypt(_int64[]);				// decrypt user string

private:
	int PublicKey;								// public key
	int PrivateKey;								// private key

	std::string strDecrypted;					//return string for Decrypt()

	int GetBigPrime();							// get a big prime number
	bool IsPrime(int);							// true if int is prime
	int GetMilliSeconds();						// from clock
	int Get_e();								//generation incryption exponent
	int Get_d();								//generation decryption exponent
	void PrimeFactorization(int, int[]);		// find prime factors of an int
	std::string IntToBin(int);					// convert int to bin
};

