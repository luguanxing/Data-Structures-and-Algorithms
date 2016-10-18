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

/*  ���򣺴����ұ�����׺���ʽ��ÿ�����ֺͷ��ţ��������־������
����Ϊ��׺���ʽ��һ���֣����Ƿ��ţ����ж�����ջ�����ŵ����ȼ���
�������Ż����ȼ������Ҷ����ţ��˳����ȼӼ�����ջ��Ԫ�����γ��Ҳ�
�����������ǰ���Ž�ջ��һֱ�����������׺���ʽΪֹ */

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