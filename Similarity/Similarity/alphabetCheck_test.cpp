#include "gmock/gmock.h"
#include "alphabetCheck.cpp"

using namespace testing;
using std::string;


TEST(TC, TC1) {
	string input1 = "asd";
	string input2 = "DSA";
	alphabetCheck app;
	EXPECT_THROW(app.getScore(input1, input2), std::invalid_argument);
}

TEST(TC, TC2) {
	string input1 = "DSA";
	string input2 = "dsa";
	alphabetCheck app;
	EXPECT_THROW(app.getScore(input1, input2), std::invalid_argument);
}

TEST(TC, TC3) {
	string input1 = "ASD";
	string input2 = "DSA";

	alphabetCheck app;
	int actual = app.getScore(input1, input2);
	int expected = 40;

	EXPECT_EQ(expected, actual);
}
