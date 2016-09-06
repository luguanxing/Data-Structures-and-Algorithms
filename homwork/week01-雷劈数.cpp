#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
using namespace std;

int wei(int n) {
	char buff[20];
	snprintf(buff, sizeof(buff), "%d", n);
	return strlen(buff);
}

int main() {
	for (int i = 1; i < 10000; i++) {	//从第j位分割s=i*i,看有无left + right = i
		int s = i * i;
		int l = wei(s);
		for (int j = 1; j < l; j++) {
			int left = s / (int)pow(10, j);
			int right = s % (int)pow(10, j);
			if (left > i || right > i)
				continue;
			if (left + right == i) {
				cout << s << endl;
				break;
			}
		}
	}
	return 0;
}
