#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
    int cas;
    cin >> cas;
    while (cas--) {
        int i, n;
        int e[10005] = {0};
        cin >> n;
        int t, k;
        for(i = 0; i < n; i++) {
            cin >> t >> k; 
            e[k] = t;
        }
        cin >> n;
        for(i = 0; i < n; i++) {
            cin >> t >> k; 
            e[k] += t;
        }
        int sum = 0;
        for(i = 0; i < 10005; i++)
            if (e[i])
                sum++;
        cout << sum << endl;
        for(i = 10000; i >=0 ; i--)
            if (e[i])
                cout << e[i] << " " << i << endl;
    }
    return 0;
}                                 