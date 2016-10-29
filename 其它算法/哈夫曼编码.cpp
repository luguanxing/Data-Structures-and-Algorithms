/*
Description
	对输入的英文大写字母序列进行统计概率，然后构建Huffman树，输出按照概率降序排序输出Huffman编码。
	 
Input
	第一行是大写字母个数n(0<n<=100)
	第二行为n个字母，中间以一个空格分隔。
	建树过程把权值较小的子树作为左孩子，数据保证建树过程不会出现左右子树权值一样的情况。

Output
	假设输入中共有m个不同的字母，按照出现概率降序输出，每个字母单独一行输出。格式如下：

	字母1 出现次数 Huffman编码
	字母2 出现次数 Huffman编码
	字母3 出现次数 Huffman编码
	…
	字母m 出现次数 Huffman编码
 
Sample Input
	10
	S S U U U S U L U U
Sample Output
	U 6 1
	S 3 01
	L 1 00
*/

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
    int weight;
	char c;
	string id;
    Node* left;
    Node* right;
    Node(int w, char cx = 0, Node* l = NULL, Node* r = NULL): weight(w), c(cx), id(""), left(l), right(r) {}
	void code();
	void find(char x);
};

char s[26];		//26个字母
int n, i, j, weight[26];	//临时变量与26个字母出现次数
int weights = 0;	//实际字母个数
bool flag;	//标记符号
vector<Node> v;		//带权结点
string temp, pid;	//临时变量

void Node::code() {
	if (!flag)
		this->id = temp + "0";
	else
		this->id = temp + "1";
	if (this->left != NULL) {
		flag = false;
		temp = this->id;
		this->left->code();
	}
	if (this->right != NULL) {
		flag = true;
		temp = this->id;
		this->right->code();
	}
}

void Node::find(char x) {
	if (flag && this->c == x) {
		pid = this->id;
		flag = false;
		return;
	}
	if (flag && this->left != NULL)
		this->left->find(x);
	if (flag && this->right != NULL)
		this->right->find(x);
}

void getdata() {
	for (i = 0; i < 26; i++) {
		weight[i] = 0;
		s[i] = 'A'+i;
	}
	cin >> n;
	for (i = 0; i < n; i++) {
		char x;
		cin >> x;
		weight[x-'A']++;
	}
	for (i = 0; i < 26; i++) 
		for (j = i+1; j < 26; j++)
			if (weight[i] < weight[j]) {
				int t = weight[j];
				weight[j] = weight[i];
				weight[i] = t;
				char x = s[j];
				s[j] = s[i];
				s[i] = x;
			}
	for (i = 0; i < 26; i++)
		if (weight[i])
			weights++;
		else
			break;
	for (i = 0; i < weights; i++) {
		Node t(weight[i], s[i]);
		v.push_back(t);
	}
}

void sortnode() {
	vector<Node>::iterator i, j;
	for (i = v.begin(); i != v.end(); i++)
		for (j = i+1; j != v.end(); j++)
			if (i->weight > j->weight) {
				Node t = *i;
				*i = *j;
				*j = t;
			}
}

void buildtree() {
	while (v.size() > 1) {
		sortnode();
		Node *t1 = new Node(v[0].weight, v[0].c, v[0].left, v[0].right);
		Node *t2 = new Node(v[1].weight, v[1].c, v[1].left, v[1].right);
		Node *newnode = new Node(v[0].weight+v[1].weight, 0, t1, t2);
		v.erase(v.begin());
		v.erase(v.begin());
		v.push_back(*newnode);
	}
}


void codetree() {
	temp = "";
	flag = false;
	v[0].left->code();
	temp = "";
	flag = true;
	v[0].right->code();
}



int main() {
	getdata();
	buildtree();
	codetree();
	for (i = 0; i < weights; i++) {
		pid = "";
		flag = true;
		v[0].find(s[i]);
		cout << s[i] << " " << weight[i]  << " " << pid << endl;
	}
    return 0;
}