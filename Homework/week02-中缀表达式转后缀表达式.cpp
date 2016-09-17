// Problem#: 19144
// Submission#: 4808790
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <stack>
#include <ctype.h>
#include <stdio.h>

using namespace std;

/*  规则：从左到右遍历中缀表达式的每个数字和符号，若是数字就输出，
即成为后缀表达式的一部分；若是符号，则判断其与栈顶符号的优先级，
是右括号或优先级低于找顶符号（乘除优先加减）则栈顶元素依次出找并
输出，并将当前符号进栈，一直到最终输出后缀表达式为止 */

int prority(char s) {
    if (s == '+' || s == '-')
        return 1;
    if (s == '*' || s == '/' || s == '%')
        return 2;
    return 0;
}

string translate(string s) {
    string r = "";
    stack<char> st;
    for (unsigned int i = 0; i < s.size(); i++) {
        if (isalpha(s[i]))
            r += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')') {
            while (st.top() != '(') {
                r += st.top();
                st.pop();
            }
            st.pop();
        } else {
            if (st.size() == 0 || prority(st.top()) < prority(s[i]))
                st.push(s[i]);
            else {
                while (st.size() && prority(st.top()) >= prority(s[i])) {
                    r += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    if (st.size())
        while (st.size()) {
            r += st.top();
            st.pop();
        }
    return r;
}

int main() {
    string s, r;
    cin >> s;
    r = translate(s);
    cout << r;
    return 0;
}                                 