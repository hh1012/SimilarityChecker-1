#include "gmock/gmock.h"
#include "split.cpp"

using namespace testing;

class LengthFixture : public Test {
public:
    LengthCheck app;

    void diagLength(int expectedPoint, string input1, string input2) {
        int actual = app.getResult(input1, input2);
        EXPECT_EQ(expectedPoint, actual);
    }
};

TEST_F(LengthFixture, PerfectLength) {
    diagLength(60, "ABCD", "BBEQ");
    diagLength(60, "WER", "WEE");
    diagLength(60, "W", "W");
}

TEST_F(LengthFixture, ZeroPointSet) {
    diagLength(0, "ABCD", "ERWERSDFSD");
    diagLength(0, "ABCD", "ERWEERWE");
    diagLength(0, "A", "AA");
}

TEST_F(LengthFixture, AOver) {
    diagLength(0, "ERWERSDABCD", "SDF");
    diagLength(0, "SDFSDF", "SDF");
    diagLength(0, "AA", "A");
}

TEST_F(LengthFixture, BOver) {
    diagLength(20, "EWRWE", "SDF");
    diagLength(15, "SQWREDF", "FDEW");

}

TEST_F(LengthFixture, TC5) {
    diagLength(15, "FDEW", "SQWREDF");
    diagLength(20, "SDF", "EWRWE");
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}