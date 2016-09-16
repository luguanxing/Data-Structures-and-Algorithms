/*
Description
检查输入字符串中的括号是否匹配。括号包括：{, }, (, ), [, ].

Input
第一行是一整数，即测试样例个数n.
以下n行，每一行是一个长度不超过100个字符的字符串。

Output
第一行是一整数，即测试样例个数n.
以下n行，每一行是一个长度不超过100的字符串。

注意：对于不符合规则的如[{]}也要检查
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int cas;
    cin >> cas;

    while (cas--) {
        string s, stack;
        stack = " ";
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{')
                stack += '{';
            else if (s[i] == '}') {
                if (i == 0)
                    flag = false;
                if (stack[stack.size() - 1] == '{')
                    stack.erase(stack.end() - 1);
                else
                    flag = false;
            }

            else if (s[i] == '(')
                stack += '(';
            else if (s[i] == ')') {
                if (i == 0)
                    flag = false;
                if (stack[stack.size() - 1] == '(')
                    stack.erase(stack.end() - 1);
                else
                    flag = false;
            }

            else if (s[i] == '[')
                stack += '[';
            else if (s[i] == ']') {
                if (i == 0)
                    flag = false;
                if (stack[stack.size() - 1] == '[')
                    stack.erase(stack.end() - 1);
                else
                    flag = false;
            }

        }
        stack.erase(stack.begin());
        if (flag && stack == "")
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
