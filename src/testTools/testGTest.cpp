#include "stdafx.h"
#include "testGTest.h"

int TEST_GTEST::Add(const int a, const int b) {
	return a + b;
}

TEST(AddTest, HandlesPositiveInput) {
	EXPECT_LT(1, TEST_GTEST::Add(1, 2));
	EXPECT_EQ(3, TEST_GTEST::Add(1, 2));
	ASSERT_LT(1, TEST_GTEST::Add(1, 2));
	ASSERT_EQ(3, TEST_GTEST::Add(1, 2));
}

