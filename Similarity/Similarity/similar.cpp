#include <iostream>
#include <string>
using namespace std;

class LenChecker {
public:
	int getScore(const string& a, const string& b) {
		if (a.length() == b.length()) {
			return MAX_SCORE;
		}
		
		int longerlen, shorterlen;
		if (a.length() > b.length()) {
			longerlen = a.length();
			shorterlen = b.length();
		}
		else {
			shorterlen = a.length();
			longerlen = b.length();
		}

		if (longerlen >= shorterlen * 2) return 0.0;
		
		int ret = static_cast<int>((1.0 - (longerlen - shorterlen) / static_cast<double>(shorterlen)) * 60);

		return ret;

	}

private:
	const int MAX_SCORE = 60.0;
};