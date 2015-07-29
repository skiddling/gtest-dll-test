// coreTest.cpp : Defines the exported functions for the DLL application.
//

extern "C" __declspec(dllexport) int mul(int a, int b)
{
	int x = a + 10;
	int y = b + 20;
	return x * y;
}

float add(float x, float y)
{
	return x + y;
}
