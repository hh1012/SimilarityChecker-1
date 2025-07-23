#include "gmock/gmock.h"
#include "similar.cpp"
using namespace testing;

TEST(TC, TC1) {
	LenChecker app;
	int actual = app.getScore("ASD", "DSA");
	int expected = 60;
	EXPECT_EQ(expected, actual);
}

TEST(TC, TC2) {
	LenChecker app;
	int actual = app.getScore("A", "BB");
	int expected = 0;
	EXPECT_EQ(expected, actual);
}

TEST(TC, TC3) {
	LenChecker app;
	int actual = app.getScore("AAABB", "BAA");
	int expected = 20;
	EXPECT_EQ(expected, actual);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}