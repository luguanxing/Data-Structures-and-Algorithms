/*
Description
 ����һ������ͼ����0,1,2,...,n-1������n�����㣬��ָ����������֮�����̾��롣

Input
 

��һ��Ϊ��������������

֮����N������������ÿ�����������ĵ�һ��Ϊ4�������������n������m, ����v1�� ����v2��

n m v1 v2

֮����m�����ԣ�ÿ������<s,t>��ʾ����s�붥��t֮����ڱߡ�

Output
����ÿ���������õ���һ�������̾��롣
*/
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int a[105][105];
int l[105][105];

int main() {
    int cas;
    cin >> cas;
    while (cas--) {
        int n, m ,v1, v2, i, j, k;
        for (i = 0; i < 105; i++) 
            for (j = 0; j < 105; j++)
                a[i][j] = l[i][j] = 999;
        cin >> n >> m >> v1 >> v2;
        for (i = 0; i < m; i++) {
            int y, x;
            cin >> y >> x;
            a[y][x] = a[x][y] = 1;
            l[y][x] = l[x][y] = 1;
        }
        for (k = 0; k < n; k++)
            for (i = 0; i < n; i++) 
                for (j = 0; j < n; j++)
                    if (l[i][k] + l[k][j] < l[i][j])
                         l[i][j] = l[i][k] + l[k][j];
        cout << l[v1][v2] << endl;      
    }
    return 0;
}                           