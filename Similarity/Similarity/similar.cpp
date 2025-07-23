#include <iostream>
#include <string>
using namespace std;

class LenChecker {
public:
	int getScore(const string& a, const string& b) {
		if (a.length() == b.length()) return 60;
	}
};