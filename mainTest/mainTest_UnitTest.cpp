#include "../UnitTest/unitTest.h"
#include "mainTest.h"

#pragma comment(lib, "../bin/unitTest.lib")


class CMainTestUT : public ::testing::Test, public ::testing::CMemLeakDetector
{
protected:
	void SetUp() override
	{
		__CHECK_MEMLEAK_BEGIN__
	}

	void TearDown() override
	{
		__CHECK_MEMLEAK_END__
	}
};


TEST_F(CMainTestUT, Case0)
{
	ASSERT_GE(fact(4), 24);
}

TEST_F(CMainTestUT, Case1)
{
	ASSERT_GE(mulx(10, 20), 800);
}

