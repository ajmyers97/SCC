//Module:	VehicleClass.cpp
//Project:	CIS023_S2018_HW5 Allen Myers
//Author:	Allen Myers
//Date:		February 24th, 2018
//Purpose:	Implementation file for VehicleClass.h
//
//
#include "stdafx.h"
#include "VehicleClass.h"


VehicleClass::VehicleClass()
{
}


VehicleClass::~VehicleClass()
{
}
void VehicleClass::SetName(string strIn)
{
	strName = strIn;
}

void VehicleClass::SetEngine(string strIn)
{
	strEngine = strIn;
}

void VehicleClass::SetStyle(string strIn)
{
	strStyle = strIn;
}

void VehicleClass::SetOccupants(string strIn)
{
	strOccupants = strIn;
}

int VehicleClass::SetVehicleTax()
{
	int VehicleTax=0;
	int engineTax=0;
	int typeTax = 0;
	int passengerLimit = 0;
	size_t pRet;							//return value for mbstowcs_s()

	for (int i = 0; i < 9; i++)
	{
		if (strEngine == "Electric")
			return engineTax= 0;
		if (strEngine == "Gasoline")
			return engineTax = 1;
		if (strEngine == "Diesel")
			return engineTax = 2;
	}
	for (int j = 0;j < 9; j++)
	{
		if (strStyle == "Passenger")
			typeTax =  1;
		if (strStyle == "SUV")
			typeTax =  2;
		if (strStyle == "Pickup")
			typeTax =  3;
		if (strStyle == "Van")
			typeTax =  4;
		return typeTax;
	}
	for (int k = 0; k < 9; k++)
	{
		passengerLimit =						//convert string to integer
			atoi(strOccupants.c_str());		//store in array
	}
	VehicleTax = typeTax + engineTax + passengerLimit;

}


string VehicleClass::GetName()
{
	return strName;
}

string VehicleClass::GetEngine()
{
	return strEngine;
}

string VehicleClass::GetStyle()
{
	return strStyle;
}

string VehicleClass::GetOccupants()
{
	return strOccupants;
}

int VehicleClass::GetVehicleTax()
{
	return VehicleTax;
}