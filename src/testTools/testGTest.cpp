#include "stdafx.h"
#include "testGTest.h"

int TEST_GTEST::add(const int a, const int b) {
	return a + b;
}

TEST(test_add, case1) {
	EXPECT_LT(1, TEST_GTEST::add(1, 2));
	EXPECT_EQ(3, TEST_GTEST::add(1, 2));
	ASSERT_LT(1, TEST_GTEST::add(1, 2));
	ASSERT_EQ(3, TEST_GTEST::add(1, 2));
}

