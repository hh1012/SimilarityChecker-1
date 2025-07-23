#include "gmock/gmock.h"
#include "similar.cpp"
using namespace testing;

TEST(TC, TC1) {
	LenChecker app;
	int expected = app.getScore("ASD", "DSA");
	EXPECT_EQ(60, expected);
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}