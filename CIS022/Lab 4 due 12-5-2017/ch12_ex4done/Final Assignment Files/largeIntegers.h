//largeIntegers.h
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :   CH12_EX4.                                       * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     * 
//*                                                                     * 
//* Purpose         : To test implementations of largeIntegers.cpp      * 
//*                                                                     * 
//* Inputs          : No input calls from user                          * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Implementation of largeIntegers.h                 * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Straight line code no sub-processes          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 12/07/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
class largeIntegers{

public:
	largeIntegers();
	largeIntegers(int size);
	void getNum();
	int getSize();
	int *getArray();
	void printNum();
	bool isSmall(largeIntegers o1, largeIntegers o2);
	void add(largeIntegers object1, largeIntegers object2);
	void subtract(largeIntegers object1, largeIntegers object2);
	void multiply(largeIntegers ob1, largeIntegers ob2);
	void compare(largeIntegers obje1, largeIntegers obje2);
	//function compares whether the numbers are equal, less than, or greater than.
	void reverse();
private:

};
