//implementation of largeIntegers.h
//Tutorial for this program and some code used from CheggStudy
//Source Site: goo.gl/me3H4E
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :       CH12_EX4                                    * 
//*                                                                     * 
//* Written by      : Allen J Myers, Michael Rearden, Robert Hanson     *
//*                                  Ryan Jeffrey                                                                      *
//*                                                                     * 
//* Purpose         : To implement largeIntegers.h                      * 
//*                                                                     * 
//* Inputs          : Number of char in num to be inputted              * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : Calls to dateType.h and dateTypeImp.cpp           * 
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
#include <string>
#include <iostream>
#include "largeIntegers.h"
void largeIntegers::setNum(int list[], int length)
{
       for (int i = 0; i < length; i++)
       {
              number = number * 10 + list[i];
      }
}
void largeIntegers::printNum(ostream&)
{
     cout << "number is: " << number;
}
void largeIntegers::getNum(istream&)
{
       cout << "Enter an integer:";
       cin >> number;
}
void largeIntegers::copyNum(const largeIntegers& right)
{
       number = right.number;
}
bool largeIntegers::equal(const largeIntegers& right) const
{
       if (right.number == number)
       {
              return true;
       }
       else
              return false;
}
bool largeIntegers::notEqual(const largeIntegers& right) const
{
       if (right.number == number)
       {
              return false;
       }
       else
              return true;
}
bool largeIntegers::greaterThan(const largeIntegers& right) const
{
       if (right.number > number)
       {
              return true;
       }
       else
              return false;
}
bool largeIntegers::lessThan(const largeIntegers& right) const
{
       if (right.number < number)
       {
              return true;
       }
       else
              return false;
}
bool largeIntegers::lessOrEqualTo(const largeIntegers& right) const
{
       if (right.number <= number)
       {
              return true;
       }
       else
              return false;
}
bool largeIntegers::greaterOrEqualTo(const largeIntegers& right) const
{
       if (right.number >= number)
       {
              return true;
       }
       else
              return false;
}
largeIntegers largeIntegers::add(const largeIntegers& num)
{
       largeIntegers n;
       n.number = number + num.number;
       return n;
}
largeIntegers largeIntegers::subtract(const largeIntegers& num)
{
       largeIntegers n;
       n.number = number - num.number;
       return n;
}
largeIntegers largeIntegers::multiply(const largeIntegers& num)
{
       largeIntegers n;
       n.number = number * num.number;
       return n;
}
largeIntegers::largeIntegers()
{
      number = 0;
}
largeIntegers::largeIntegers(int list[], int length, char numSign)
{
       for (int i = 0; i < length; i++)
       {
              number = number * 10 + list[i];
       }
       if (numSign == '-')
       {
              number = number-(2*number);
       }

}