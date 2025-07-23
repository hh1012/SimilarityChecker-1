#include <iostream>
#include <string>
#include <stdexcept>
using std::string;

class alphabetCheck {
public:
	int getScore(const string& input1, const string input2) {
		for (char c : input1) {
			if (c < 'A' || c>'Z') {
				throw std::invalid_argument("Must be capital letter");
			}
		}
		for (char c : input2) {
			if (c < 'A' || c>'Z') {
				throw std::invalid_argument("Must be capital letter");
			}
		}
		return 40;
	}
};