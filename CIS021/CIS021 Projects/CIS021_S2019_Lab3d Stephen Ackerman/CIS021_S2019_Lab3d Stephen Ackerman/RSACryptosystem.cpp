// Project: CIS021_S2019_Lab3d Stephen Ackerman
// Module:  RSACryptosystem.h
// Date:    Feb 14, 2019
// Author:  Stephen Ackerman
// Appended on 2/19/2019 by Allen Myers
// Purpose: Implementation file for RSACryptoSystem

#include "stdafx.h"
#include "RSACryptosystem.h"


RSACryptosystem::RSACryptosystem()
{
	PublicKey = GetBigPrime();			// create public key

	do
	{
		PrivateKey = GetBigPrime();		// create private key
	} while (PrivateKey == PublicKey);	// must be unique
}


RSACryptosystem::~RSACryptosystem()
{
}

void RSACryptosystem::Encrypt(std::string strRaw, _int64 _intEncrypt[])
{
	// https://simple.wikipedia.org/wiki/RSA_(algorithm)

	// c = m ^ e mod n
	// c = return, encrypted string
	// m - raw, unencrypted string
	// e = exponent, created from input key
	// n = modulous, from public and private key

	int m = 0;				// character from strRaw
	int e = Get_e();		// calculated exponent
	int n = PublicKey * PrivateKey;	// calculate mod using combined key
	int iIndex = 0;			// index of _intEncrypt[]

	// clear return array
	memset(_intEncrypt, 0, sizeof(_int64) * 100);

	//encrypt each char
	for (UINT i = 0; i < strRaw.length(); i++)
	{
		m = strRaw[i];				// char from input string
		std::string eBin = IntToBin(e);	// binary version of e
		_int64 _intEnc = 1;			// subtotal as character is encrypted
		_int64 _intPower = m % n;	// offset character mod modulous

		// roll through binary listing of e
		for (int j = eBin.length() - 1; j >= 0; j--)
		{
			
			if (eBin[j] == '1')			// 1 true, 0 false
			{
				_intEnc = (_int64)((_intEnc * _intPower) % n);
			}
			_intPower = (_intPower * _intPower) % n;
		}
		_intEncrypt[iIndex++] = _intEnc;	// store encrypted char
	}
}

std::string RSACryptosystem::Decrypt(_int64 _intEnc[])
{
	//m=c^d mod n
	//m=return, decrypted sring
	//c= encrypted array
	//d==exponent, created from input keys
	//n=moduloid from public and private keys

	_int64 m = 0;								//individual item from input array
	int d = Get_d();							//calculated exponent
	std::string dBin = IntToBin(d);				//converted d to binary string
	int n = PublicKey*PrivateKey;				//calculated modulus
	int iIndex = 0;								//index of _intEnc[]

	while (_intEnc[iIndex] != 0)				//roll through array
	{
		m = _intEnc[iIndex++];					//current array element
		_int64 _intSub = 1;						//sub total as character is decrypted
		_int64 _intPower = m%n;					//offset char mod modulus

		for (int i = dBin.length() - 1;i >= 0; i--)			//count down along bits
		{
			if (dBin[i] == '1')					//modular exponetiation
				_intSub = (_int64)((_intSub*_intPower) % n);
			_intPower = (_intPower*_intPower) % n;
		}
		strDecrypted += (char)_intSub;			//append decryption char to output string
	}
	return strDecrypted;						//return decrypted string
}

int RSACryptosystem::GetBigPrime()
{
	int iMilliseconds = GetMilliSeconds();		// from clock
	int iBigPrime = 31;							// minimum 31
	if (iMilliseconds > 31)						// find highest prime
	{
		for (int i = iMilliseconds; i > 31; i--)
		{
			if (IsPrime(i))						// only use primes
			{
				iBigPrime = i;					// set value
				break;							// jump out of for loop
			}
		}
	}
	return iBigPrime;
}

bool RSACryptosystem::IsPrime(int iIn)
{
	for (int i = 2; i <= iIn / 2; i++)
	{
		if (iIn % i == 0)
		{
			return false;
		}
	}
	return true;
}

int RSACryptosystem::GetMilliSeconds()
{
	SYSTEMTIME tLocalTime;		// structur that holds time
	GetLocalTime(&tLocalTime);	// get structure

	return tLocalTime.wMilliseconds;
}

int RSACryptosystem::Get_e()
{
	int e = 1;							// exponent
	int iTfactors[100];					// prime factors for T
	int n = PublicKey * PrivateKey;		// modulous

	// computer totient phi of n
	int t = (PublicKey - 1) * (PrivateKey - 1);

	PrimeFactorization(t, iTfactors);			// get list of prime factors
	
	int i = 0;
	int iLargestFactor = 0;
	do
	{
		iLargestFactor = iTfactors[i];		// hold largest so far
	} while (iTfactors[++i] != 0);

	i = iLargestFactor + 1;					// continue past largest
	do
	{
		if (IsPrime(i))						// is this a prime
		{
			e = i;							// this prime is our e
			break;
		}
	} while (i++ < t);						// until we find a prime


	return e;
}

int RSACryptosystem::Get_d()
{

	int d = 1;								//decryption exponent
	int n = PublicKey*PrivateKey;			//modulus based on keys
	int e = Get_e();						//start with encryption exponent
	int iChinRem = 1;						//chinese remainder
	int t = (PublicKey - 1)*(PrivateKey - 1);//totient phi of n

	while ((t*iChinRem + 1) % e != 0)			//find chinese remainder
		iChinRem++;
	d = (t*iChinRem + 1) / e;					//d congruant 1 (mod totient)


	return d;
}

void RSACryptosystem::PrimeFactorization(int iIn, int iFactors[])
{
	int iBase;			// modified number
	int iIndex = 0;		// index of array

	memset(iFactors, 0, sizeof(int) * 100);

	if (!IsPrime(iIn))	// make sure input is not prime
	{
		iBase = iIn;				// copy of input
		while (iBase > 1)			// continue until not factorable
		{
			for (int i = 2; i <= iIn / 2; i++)	// factor
			{
				if (IsPrime(i))				// is this index a prime factor?
				{
					if (iBase % 1 == 0)
					{
						iFactors[iIndex++] = i;		// store the factor
						iBase = iBase / i;		// remove this copy
						break;
					}
				}
			}
		}
	}
}

std::string RSACryptosystem::IntToBin(int iIn)
{
	std::string strBinary;

	std::stringstream ss;				// stream
	ss << std::bitset<32>(iIn);				// generate 32 bit binary
	strBinary = ss.str();

	return strBinary;
}
