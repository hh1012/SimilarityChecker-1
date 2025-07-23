#include <string>
#include <vector>
#include <set>

using std::string;
using std::vector;
using std::set;

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

class CharChecker {
public:
    int getResult(string input1, string input2) {
        if (isPerfectSameChars(input1, input2)) return CHAR_MAX_POINT;
        if (isPerfectDifferentChars(input1, input2)) return CHAR_MIN_POINT;
        return getPartialCharPoint(input1, input2);
    }

private:
    vector<char> getBreakString(string str) {
        std::set<char> st1;

        for (char ch : str) {
            st1.insert(ch);
        }

        vector<char> t1;
        for (char ch : st1) {
            t1.push_back(ch);
        }

        return t1;
    }

    bool isPerfectSameChars(const string& input1, const string& input2) {
        int size1 = getBreakString(input1).size();
        int size2 = getBreakString(input2).size();
        if (size1 != size2) return false;

        int sameCount = getSameCharCount(input1, input2);
        if (size1 == sameCount) return true;
        return false;
    }

    bool isPerfectDifferentChars(const string& input1, const string& input2) {
        return (getSameCharCount(input1, input2) == 0);
    }
    int getSameCharCount(const string& input1, const string& input2) {
        vector<char> input1Chars = getBreakString(input1);
        vector<char> input2Chars = getBreakString(input2);

        int result = 0;
        for (char input1Char : input1Chars) {
            for (char input2Char : input2Chars) {
                if (input1Char == input2Char) {
                    result++;
                }
            }
        }

        return result;
    }

    int getTotalCount(string input1, string input2) {
        vector<char> totalChars = getBreakString(input1 + input2);
        return totalChars.size();
    }

    int getPartialCharPoint(string input1, string input2) {
        int totalCount = getTotalCount(input1, input2);
        int sameCount = getSameCharCount(input1, input2);

        return CHAR_MAX_POINT * sameCount / totalCount;
    }

private:
    const int CHAR_MAX_POINT = 40;
    const int CHAR_MIN_POINT = 0;
};