#include <iostream>
#include <string.h>
#include <string>
using namespace std;

bool match(string a, string b) {
	if (a.length() != b.length())
		return false;
	for(int i = 0; i < a.length(); i++)
		if (a[i] == 'A' && b[i] != 'T')
			return false;
		else if (a[i] == 'T' && b[i] != 'A')
			return false;
		else if (a[i] == 'C' && b[i] != 'G')
			return false;
		else if (a[i] == 'G' && b[i] != 'C')
			return false;
	return true;
}

int main() {
	int cas;
	cin >> cas;
	while (cas--) {
		string a[105];
		bool b[105];
		int num;
		int i, j;
		cin >> num;
		for (i = 0; i < num; i++)
			cin >> a[i];
		memset(b, true, 100);
		int sum = 0;
		for (i = 0; i < num; i++)
			for (j = i+1; j < num; j++)
				if (b[i] && b[j] && match(a[i],a[j])) {
					b[i] = b[j] = false;
					sum++;
				}
		cout << sum << endl;
	}
	return 0;
}
