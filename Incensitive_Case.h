#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cwctype>

using namespace std;

inline bool caseInsCharCompareN(char a, char b) {
	return(toupper(a) == toupper(b));

}

inline bool caseInsCharCompareW(wchar_t a, wchar_t b) {
	return(towupper(a) == towupper(b));

}
bool caseInsCompare(const string& s1, const string& s2) {
	return((s1.size() == s2.size()) &&
		equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));

}

bool caseInsCompare(const wstring& s1, const wstring& s2) {
	return((s1.size() == s2.size()) &&
		equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareW));

}