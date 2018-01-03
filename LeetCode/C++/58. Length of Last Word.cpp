#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		while (s.size() && s[s.size()-1] == ' ') {
			s = s.substr(0, s.size()-1);
		}
		int index = s.size()-1;
		while (index >= 0) {
			if (s[index] == ' ')
				break;
			else
				index--;
		}
		s = s.substr(index+1, s.size());
		return s.size();
    }
};  

int main() {
	Solution so;
	cout << so.lengthOfLastWord(" ");
	return 0;
}