#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000005

class JEW {
    public:
        int m;
        int v;
};
JEW jew[MAX];
vector<int> c;
int n, k;

bool comp(JEW a,JEW b) {	//先排价值，后排重量
     if (a.v < b.v)
         return false;
     if (a.v == b.v && a.m > b. m)
         return false;
     return true;
}

int main() {  
    cin >> n >> k;
    int i, j;
    for (i = 0; i < n; i++)
        cin >> jew[i].m >> jew[i].v;
    for (i = 0; i < k; i++) {
        int x;
        cin >> x;
        c.push_back(x);
    }
    sort(jew, jew+n, comp);		//珠宝排序
    sort(c.begin(), c.end());		//袋子容量排序
    int sum = 0;
    for (i = 0; i < n; i++) {
        vector<int>::iterator it;
        for (it = c.begin(); it != c.end(); it++)
            if (jew[i].m <= *it) {
                sum += jew[i].v;
                c.erase(it);	//装了珠宝的袋子去掉
                break;
            }
    }
    cout << sum << endl;
    return 0;
}  