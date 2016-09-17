// Problem#: 19146
// Submission#: 4808751
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <stack>
#include <stdio.h>

using namespace std;

int main() {
    int cas;
    cin >> cas;
    while (cas--) {
        stack<double> st;
        string s;
        double t, t1, t2;
        cin >> s;
        for (unsigned int i = 0; i < s.size(); i++) {

            if ('a' <= s[i] && s[i] <= 'z')
                st.push(s[i] - 'a' + 1);

            if (s[i] == '+') {
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();
                t = t1 + t2;
                st.push(t);
            }

            if (s[i] == '-') {
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();
                t = t2 - t1;
                st.push(t);
            }

            if (s[i] == '*') {
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();
                t = t1 * t2;
                st.push(t);
            }

            if (s[i] == '/') {
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();
                t = t2 / t1;
                st.push(t);
            }
        }

        double num = st.top();
        st.pop();
        printf("%.2lf\n", num);
    }
    return 0;
}                                 