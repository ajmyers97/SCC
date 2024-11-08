// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here

#define TCHAR_SIZE 128					// size of TCHAR

#include <string>		// string library
#include <sstream>		// stream library for data conversion
#include <fstream>		// file stream library

using namespace std;	// Use standard namespaces

#include "NodeClass.h"
