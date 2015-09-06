// coreTest.cpp : Defines the exported functions for the DLL application.
//

// tells easylogging++ that it's used for DLL
#define ELPP_AS_DLL
// tells easylogging++ to export symbols
#define ELPP_EXPORT_SYMBOLS

#include "../easylogginpp/easylogging++.h"

INITIALIZE_EASYLOGGINGPP


extern "C" __declspec(dllexport) int mul(int a, int b)
{
	int x = a + 10;
	int y = b + 20;
	return x * y;
}

double add(float x, float y)
{
	LOG(INFO) << "add";
	return x + y;
}
