#include <iostream>
using namespace std;

int main() {
	int n, i, j;
	int a[20][20];
	cin >> n;
	if (n <= 0 || n > 20) {
		cout << "invalid num!\n";
		return 0;
	}

	for (i = 0; i < n; i++)	//��������
		for (j = 0; j < n; j++)
			cin >> a[i][j];

	bool flag = 1;	//ȡ��һ��Ϊ׼
	int sum = 0;
	int sum2 = 0;
	for (i = 0; i < n; i++)
		sum += a[0][i];

	for (i = 0; i < n && flag; i++) {	//�жϸ���
		sum2 = 0;
		for (j = 0; j < n; j++)
			sum2 += a[i][j];
		if (sum2 != sum)
			flag = 0;
	}

	for (i = 0; i < n && flag; i++) {	//�жϸ���
		sum2 = 0;
		for (j = 0; j < n; j++)
			sum2 += a[j][i];
		if (sum2 != sum)
			flag = 0;
	}

	sum2 = 0;
	for (i = 0; i < n && flag; i++)	//�ж϶Խ���1
		sum2 += a[i][i];
	if (sum2 != sum)
		flag = 0;

	sum2 = 0;
	for (i = 0; i < n && flag; i++)	//�ж϶Խ���2
		sum2 += a[i][n - 1 -i];
	if (sum2 != sum)
		flag = 0;

	if (flag)
		cout << "yes\n";
	else
		cout << "no\n";
	return 0;
}
