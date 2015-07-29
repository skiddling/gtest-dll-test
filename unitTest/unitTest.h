#pragma once

#include "windows.h"
#include "../googletest/include/gtest.h"


#define __CHECK_MEMLEAK_BEGIN__ BeginSession();
#define __CHECK_MEMLEAK_END__ EndSession();


namespace testing
{
	class CMemLeakDetector
	{
	public:
		void BeginSession()
		{
			_CrtMemCheckpoint(&memStateBegin);
		}

		void EndSession()
		{
			_CrtMemState memStateEnd;
			_CrtMemState memStateDiff;
			_CrtMemCheckpoint(&memStateEnd);
			ASSERT_EQ(_CrtMemDifference(&memStateDiff, &memStateBegin, &memStateEnd), 0) << "Memory Leak!!!";
		}

	protected:
		_CrtMemState memStateBegin;
	};
}

