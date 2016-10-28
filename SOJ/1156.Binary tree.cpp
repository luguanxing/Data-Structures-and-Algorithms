#include <iostream>
 
using namespace std;
 
struct Node {
    bool root;
    char data;
    int left,right;
};
Node node[1005];

void preorder(Node t) {
	cout << t.data;
	if (t.left)
		preorder(node[t.left]);
	if (t.right)
		preorder(node[t.right]);
}

int main() {
	int n;
	while (cin >> n) {
		int i;
		for (i = 0; i < 1005; i++) {
			node[i].data = 'x';
			node[i].left = node[i].right = 0;
			node[i].root = true;
		}
		int num, left, right;
		char c;
		for (i = 0; i < n; i++) {
			cin >> num >> c >> left >> right;
			node[num].data = c;
			node[num].left = left;
			node[num].right = right;
			node[left].root = node[right].root =false;
		}
		for (i = 0; i < 1005; i++)
			if (node[i].root && node[i].data != 'x')
				break;
		preorder(node[i]);
		cout << endl;
	}
	return 0;
}
/*
方法2：
#include<iostream>
#include<deque>
using namespace std;

class Node {
	public:
		int data;
		char c;
		Node* left;
		Node* right;
		Node(int x, char cx):data(x), c(cx), left(NULL), right(NULL) {};
		void insert(int datax, char cx, int father, bool left);
		Node* find(int datax);
		void interchange();
		void preorder();
		void show();
};

Node *place = NULL;
Node* Node::find(int datax) {
	if (this->data == datax) {
		place = this;
		return NULL;
	} if (this->left != NULL)
		this->left->find(datax);
	if (this->right != NULL)
		this->right->find(datax);
	return NULL;
}

void Node::insert(int datax, char cx, int father, bool left) {	//插入需要信息:数据，要插入地方父节点，方式
	place = NULL;
	find(father);
	if (place == NULL) {
		cout << "not found!" << endl;
		return;
	} else {
		if (left) {
			if (place->left != NULL)
				cout << "failed!" << endl;
			else
				place->left = new Node(datax, cx);
		} else {
			if (place->right != NULL)
				cout << "failed!" << endl;
			else
				place->right = new Node(datax, cx);
		}
	}
}

void Node::preorder() {
	cout << this->c << " ";
	if (this->left != NULL)
		this->left->preorder();
	if (this->right != NULL)
		this->right->preorder();
}

void Node::show() {		//输出格式
	deque<Node> de, de2;
	Node x(-1, 'x');
	de.push_back(*this);
	while (de.size()) {
		de2 = de;
		int size = de2.size();	//本行元素个数
		for (int i = 0; i < size; i++){
			Node p = de2.front();
			if (p.data != -1) {
				if (p.left != NULL)
					de.push_back(*p.left);
				else
					de.push_back(x);
				if (p.right != NULL)
					de.push_back(*p.right);
				else
					de.push_back(x);
				cout << p.c;
			} else {
				cout << "_";
			}
			cout << " ";
			de.pop_front();
			de2.pop_front();
		}
		cout << endl;
	}
}

int main() {

	int n;

	while (cin >> n) {

		int num[3005];
		char c[3005];
		int left[3005];
		int right[3005];
		int i, j;

		for (i = 0; i < n; i++)
			cin >> num[i] >> c[i] >> left[i] >> right[i];

		Node tree(num[0], c[0]);

		for (i = 0; i < n; i++) {	//从每个结点num[i]找子元素left[i],right[i];
			if (left[i]) {
				for (j = 0; j < n; j++)
					if (left[i] == num[j]) {
						tree.insert(num[j], c[j], num[i], true);
						break;
					}
			}
			if (right[i]) {
				for (j = 0; j < n; j++)
					if (right[i] == num[j]) {
						tree.insert(num[j], c[j], num[i], false);
						break;
					}
			}
		}
		
		cout << endl;
		cout << endl;
		cout << endl;
		tree.show();
		cout << endl;
		cout << endl;
		
		tree.preorder();
		cout << endl;
	}
	
	return 0;
} 
*/