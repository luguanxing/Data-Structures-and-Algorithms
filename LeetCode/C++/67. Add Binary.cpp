#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		cout << a << endl;
		cout << b << endl;
		int alen = a.size();
		int blen = b.size();
		int *x = new int[alen+1];
		int *y = new int[blen+1];
		string ret;
		x[0] = 0; y[0]= 0;
		for (int i = 1; i <= alen; i++)
			if (a[i-1] == '0')
				x[i] = 0;
			else
				x[i] = 1;
		for (int i = 1; i <= blen; i++)
			if (b[i-1] == '0')
				y[i] = 0;
			else
				y[i] = 1;
		if (alen < blen) {
			for (int i = 0; i < alen; i++) 
				y[blen - i] += x[alen - i];
			for (int i = 0; i < blen; i++)
				if (y[blen - i] >= 2) {
					y[blen - i] -= 2;
					y[blen - i - 1] += 1;
				}
			if (y[0])
				ret += y[0] + '0';
			for (int i = 1; i <= blen ; i++)
				ret += y[i] + '0';
			return ret;
		} else {
			for (int i = 0; i < blen; i++)
				x[alen - i] += y[blen - i];
			for (int i = 0; i < alen; i++)
				if (x[alen - i] >= 2) {
					x[alen - i] -= 2;
					x[alen - i - 1] += 1;
				}
			if (x[0])
				ret += x[0] + '0';
			for (int i = 1; i <= alen ; i++)
				ret += x[i] + '0';
			return ret;
		}
		return NULL;
    }
};

int main() {
	Solution so;
	cout << so.addBinary("1", "1111");
    return 0;
}