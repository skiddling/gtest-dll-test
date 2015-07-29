// unitTest.cpp : Defines the exported functions for the DLL application.
//

#include "unitTest.h"


class CGlobalEnv : public testing::Environment
{
public:
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{
	}
};


static void Run(int* argc, wchar_t* argv[])
{
	testing::AddGlobalTestEnvironment(new CGlobalEnv());
	testing::InitGoogleTest(argc, argv);
	RUN_ALL_TESTS();
}

extern "C" __declspec(dllexport) int RunUnitTest(LPCWSTR lpszCmdLine)
{
	// Need explicit LoadLibrary!
	LoadLibrary(L"coreTest.dll");

	int argc = 0;
	LPWSTR *argv = ::CommandLineToArgvW(lpszCmdLine, &argc);

	// Convert arg '-ut' to exe path.
	WCHAR szExe[MAX_PATH] = { 0 };
	::GetModuleFileName(NULL, szExe, MAX_PATH);
	LPWSTR *fakev = new LPWSTR[argc];
	fakev[0] = szExe;
	for (int i = 1; i < argc; i++)
		fakev[i] = argv[i];
	Run(&argc, fakev);

	if (argc <= 1 || _wcsicmp(fakev[1], L"--disable_pause") != 0)
		system("pause");
	delete fakev;

	return 0;
}



