#include "windows.h"
#include "string"


int main(int argc, TCHAR* argv[])
{
	if ((argc == 3) && (wcsncmp(argv[1], L"-ut", 3) == 0))
	{
		std::wstring szCmdLine = L"";
		szCmdLine.append(argv[1]);
		szCmdLine.append(L" ");
		szCmdLine.append(argv[2]);

		HMODULE h = ::LoadLibraryW(L"unitTest.dll");
		typedef int(*RunUnitTest)(LPCWSTR);
		RunUnitTest p = (RunUnitTest)::GetProcAddress(h, "RunUnitTest");
		return p(szCmdLine.c_str());
	}

	// TODO: product code
	return 0;
}

