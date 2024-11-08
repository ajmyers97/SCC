//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH3_EX9                                           * 
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : To cause a message to display on the system       * 
//*                   console. This program will be executed from the   * 
//*                   terminal at the computer room door by personnel   * 
//*                   needing service.                                  * 
//*                                                                     * 
//* Inputs          : User enters HELLO on the terminal command line    * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : No internal or external calls                     * 
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
//* 09/01/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

#include <iostream>
using namespace std;

int main(){
    cout<<"Allen Myers\t"<<"CH3_EX9\t"<<"CH3_EX9.exe"<<endl;
    const double PROFIT_PERCENT=0.01;    
    double merchandiseCost,storeRent,salaries,electricityCost,totalCost,profit,markupPercent,merchPlus15,merchPlusProfit;

    cout<<"What is the merchandise cost? ";
    cin>>merchandiseCost;

    merchPlus15=(merchandiseCost+(merchandiseCost*(.15)));
    merchPlusProfit=(merchPlus15+(merchandiseCost*(.10)));
    cout<<"\t Merchandise plus 15% for discount: "<<"$"<<merchPlus15<<endl;
    cout<<"\t Merchandise Total Sales for 10% profit: "<<"$"<<merchPlusProfit<<endl;


    cout<<"What is the employee salaries? ";
    cin>>salaries;
    cout<<"What is the yearly rent on the store? ";
    cin>>storeRent;
    cout<<"What is the cost for electricity? ";
    cin>>electricityCost;

    totalCost=salaries+storeRent+electricityCost+merchPlusProfit;
    cout<<"\tTotal revenue needed for all costs= "<<totalCost<<endl;
    markupPercent=(totalCost/merchandiseCost)*100;
    cout<<"Merchandise should be marked up by approximately "<<markupPercent<<"%"<<endl;
}