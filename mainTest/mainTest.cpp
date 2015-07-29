// mainTest.cpp : Defines the entry point for the console application.
//

#include "windows.h"
#include "mainTest.h"
#include "../coreTest/coreTest.h"

int fact(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}

int mulx(int a, int b)
{
	HMODULE h = ::LoadLibraryW(L"coreTest.dll");
	typedef int(*mul)(int, int);
	mul p = (mul)::GetProcAddress(h, "mul");
	return p(a, b);
}

