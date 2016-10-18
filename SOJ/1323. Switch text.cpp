#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

bool isblank(string s) {
	if (s == "")
		return true;
	while (s[0] == ' ')
		s.erase(s.begin());
	if (s.length())
		return false;
	else
		return true;
}

string switchtext(string s) {
	string a, b;
	if (s.length() & 1) {
		a = s.substr(0, s.length()/2+1);
		b = s.substr(s.length()/2+1, s.length());
	} else {
		a = s.substr(0, s.length()/2);
		b = s.substr(s.length()/2, s.length());
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	return a+b;
}

int main() {
	char s1[200];
	char s2[200];

	while (	gets(s1) ) {
		gets(s2);
		if (!isblank(s1) && !isblank(s2)) {
			cout << switchtext(s2) << endl;
			cout << switchtext(s1) << endl;
		} else if ( !isblank(s1) && isblank(s2) )
			cout << switchtext(s1) << endl;
		else if ( isblank(s1) && !isblank(s2) )
			cout << switchtext(s2) << endl;
		else ;
	}

	return 0;
}
