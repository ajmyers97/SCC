//Module:	VehicleClass.h
//Project:	CIS023_S2018_HW5 Allen Myers
//Author:	Allen Myers
//Date:		February 24th, 2018
//Purpose:	Header file for VehicleClass
//
//
#pragma once
class VehicleClass
{
public:
	VehicleClass();
	~VehicleClass();

	void SetName(string);						//store strname
	void SetEngine(string);						//store strcover
	void SetStyle(string);					//store strcategory
	void SetOccupants(string);						//store strgenre
	int SetVehicleTax();					//sets the vehicle tax

	string GetName();							//return strname
	string GetEngine();							//return strcover
	string GetStyle();						//return strcategory
	string GetOccupants();							//return strgenres
	int GetVehicleTax();						//returns vehicle tax

private:
	string strName;								//hold file data
	string strEngine;
	string strStyle;
	string strOccupants;
	int VehicleTax;
};

