// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#define ARRAY_SIZE 9999					//size of input file

#include <fstream>							//file input/output
#include <iostream>							//i/o
#include <iomanip>							//formatting
#include <string>							//string library
#include <windows.h>						//time
#include <vector>							//vectors

using namespace std;						//standard namespaces

#include "MergeSortIterative.h"				//merge sort with looping
#include "MergeSortRecursive.h"				//merge sort with recursion
