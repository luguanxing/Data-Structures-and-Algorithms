#include <iostream>
#include <string>
using namespace std;

string isbn;

string getisbn(string s) {
    int sum = 0;
    int weight = 10;
    char lastchar;
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]))
            sum += (s[i]-'0') * weight--;
    if (sum % 11 == 1)
        lastchar = 'X';
    else if (sum % 11 == 0)
        lastchar = '0';
    else
        lastchar = '0' + 11 - sum%11;
    string isbn = s + '-' + lastchar;
    return isbn;
}

int main() {
    string t;
    while (cin >> t)
        cout << getisbn(t) << endl;
    return 0;
}
