#include <string>

using std::string;

class LengthCheck {
public:
    int getResult(string input1, string input2) {
        int A = std::max(input1.length(), input2.length());
        int B = std::min(input1.length(), input2.length());

        if (isSame(A, B)) return LENGTH_MAX_POINT;
        if (isDoubleLength(A, B)) return LENGTH_MIN_POINT;

        return getPartialLengthPoint(A, B);
    }

private:
    bool isSame(int A, int B) {
        return A == B;
    }

    bool isDoubleLength(int A, int B) {
        return A >= B * 2;
    }

    int getPartialLengthPoint(int A, int B) {
        int Gap = A - B;
        return (LENGTH_MAX_POINT - (LENGTH_MAX_POINT * Gap) / B);
    }

    const int LENGTH_MAX_POINT = 60;
    const int LENGTH_MIN_POINT = 0;
};