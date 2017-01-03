/*
Description
 给定一个无向图，用0,1,2,...,n-1代表其n个顶点，求指定两个顶点之间的最短距离。

Input
 

第一行为测试样例总数；

之后是N个测试样例，每个测试样例的第一行为4个数：顶点个数n，边数m, 顶点v1， 顶点v2。

n m v1 v2

之后是m行数对，每个数对<s,t>表示顶点s与顶点t之间存在边。

Output
对于每个样例，用单独一行输出最短距离。
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