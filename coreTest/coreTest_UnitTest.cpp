#include "coreTest.h"
#include "../unitTest/unitTest.h"

#pragma comment(lib, "../bin/unitTest.lib")


class CCoreTestUT : public ::testing::Test, public ::testing::CMemLeakDetector
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


TEST_F(CCoreTestUT, Case0)
{
	ASSERT_GE(add(1.23, 4.56), 5.79);
}

