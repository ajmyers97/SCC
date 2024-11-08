//Module:	CIS021_S2019_Lab1b Allen Myers
//Project:	CIS021_S2019_Lab1b Allen Myers.cpp
//Author:	Allen Myers
//Date:		January 17th 2019
//Purpose:	Review creation of a console project.
//			Perform simple mathematical tasks.
//			Understand logic requirements of postulates.
//

#include "stdafx.h"
#include <iostream>						//standard i/o library
#include <iomanip>						//standard formatting library

using namespace std;					//use standard namespaces


int main()
{
	int p, q, r, s;						//user input
	char NOT = 0xBF;					//hook character

	//enter values
	printf("Enter integer values for: \n");
	printf("p=");
	cin >> p;
	printf("q=");
	cin >> q;
	printf("r=");
	cin >> r;
	printf("s=");
	cin >> s;
	printf("\n\n");						//new line char
//Axiom 1							//prints to screen
	printf("Axiom 1. Things which are equal to the same thing are also equal to one another.\n");
	printf("Proposition: If p=r and q=r, then p=q \n\n");

	//show values
	printf("p=%i\n", p);
	printf("q=%i\n", q);
	printf("r=%i\n", r);
	printf("s=%i\n\n", s);

	//show equality
	if ((p == r) && (q == r))
		printf("Therefore: p=q");
	else
		printf("Therefore: p %c= q", NOT);
	printf("\n\n");						//blank line

//Axiom 2							//prints to screen
	printf("Axiom 2. If equals are added to equals, the wholes are equal.\n");
	printf("Proposition:(p+q)=(r+s). \n \n");

	//show values
	printf("(p+q)=(%i+%i)=%i\n", p, q, p + q);
	printf("(r+s)=(%i+%i)=%i\n", r, s, r + s);

	//show equality
	printf("Conclusion: ");
	if ((p + q) == (r + s))
		printf("(p+q)=(r+s)\n");
	else
		printf("(p+q) %c = (r+s) \n", NOT);
	printf("\n\n");						//blank line

//Axiom 3							//prints to screen
	printf("Axiom 3. If equals are subtracted to equals, the remainders are equal.\n");
	printf("Proposition:(p-q)=(r-s). \n \n");

	//show values
	printf("(p-q)=(%i-%i)=%i\n", p, q, p - q);
	printf("(r-s)=(%i-%i)=%i\n", r, s, r - s);

	//show equality
	printf("Conclusion: ");
	if ((p - q) == (r - s))
		printf("(p-q)=(r-s)\n");
	else
		printf("(p-q) %c =(r-s) \n", NOT);
	printf("\n\n");						//blank line
//Axiom 4: Skip b/c requires geometry, will be covered later
	printf("\n\n");						//blank line


//Axiom 5.
	printf("Axiom 5. The whole is greater than the part \n");
	printf("Propostion: p> (p/2) \n\n");

	//show values
	printf("Assume p as the whole: p= %i\n", p);
	printf("Assume p/2 as the part: p/2=%f\n\n", p / 2.0);

	//show relation
	printf("Conclusion: ");
	if (p > (p / 2.0))
		printf("p > (p/2)");
	else
		printf("p%c>(p/2)", NOT);

	cout << endl << endl;				//blank line before closing
	system("Pause");					//pause before clsoing
    return 0;
}

