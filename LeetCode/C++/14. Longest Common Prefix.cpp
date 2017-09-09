#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0)
		return "";
	string result = "";
	bool flag = true;
	int index = 0;
	while (flag && index < strs.at(0).length()) {
		result += strs.at(0).at(index++);
		for (int i =0; i< strs.size(); i++) {
			string str =  strs.at(i);
			if (strncmp(str.c_str(), result.c_str(), index) != 0) {
					flag = false;
					break;
			}
		}
	}
	if (!flag)
		result = result.erase(result.size()-1);
	return result;
}

int main() {
	vector<string> v;
	string s1 = "haa";
	string s2 = "hafucku";
	v.push_back(s1);
	v.push_back(s2);
	cout << longestCommonPrefix(v) << endl;
	return 0;
}