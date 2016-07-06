# 字符串替换
http://sdsy.openjudge.cn/challenges/02/

###描述
将字符串s中所有的字符串source替换为字符串object。

###输入
一共3行。
第一行是一个字符串s。
4第二行是一个字符串source。
第三行是一个字符串object。
保证最后得到的字符串,s,source和object各自的长度均小于等于1000。
###输出
只有一行，即经过替换后的s。如果在s中没有发现source,直接输出"Not found"即可.
###样例输入
Good morning! I'm Tony.
o
Nice
###样例输出
GNiceNiced mNicerning! I'm TNiceny.

<br><br><br>
# 源码
```
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string str_replace(string s, string so, string ob) {
	string result;
	if (s.find(so) == -1) {
		result = "Not found\n";
	} else {
		int lso = so.length();
		while (s.find(so) != -1) {
			while (s.find(so) != 0) {
				result += s[0];
				s.erase(s.begin());
			}
			result += ob;
			s.erase(0, lso);
		}
		result += s;
	}
	return result;
}

int main() {
	string s, so, ob;
	char ss[50000];
	gets(ss); s = ss;
	gets(ss); so = ss;
	gets(ss); ob = ss;
	string answer = str_replace(s, so, ob);
	cout << answer << endl;
    return 0;
}

```
