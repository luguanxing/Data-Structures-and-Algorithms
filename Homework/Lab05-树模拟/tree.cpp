#include<iostream>
#include<deque>
using namespace std;

class Node {
	public:
		int data;
		Node* left;
		Node* right;
		Node(int x):data(x), left(NULL), right(NULL) {};
		void insert(int datax, int father, bool left);
		Node* find(int datax);
		void show();
		void interchange();
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

void Node::insert(int datax, int father, bool left) {	//插入需要信息:数据，要插入地方父节点，方式
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
				place->left = new Node(datax);
		} else {
			if (place->right != NULL)
				cout << "failed!" << endl;
			else
				place->right = new Node(datax);
		}
	}
}

void Node::show() {		//输出格式
	deque<Node> de, de2;
	Node x(-1);
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
				cout << p.data;
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

void Node::interchange() {		//遍历交换所有左右结点指针
	Node *p;
	if (this->left != NULL && this->right != NULL) {
		p = this->left;
		this->left = this->right;
		this->right= p;
	} else {
		p = this->left;
		this->left = this->right;
		this->right= p;
	}
	if (this->left != NULL)
		this->left->interchange();
	if (this->right != NULL)
		this->right->interchange();
}

int main() {

	int n;
	int a[300];
	

	Node tree(1);
	tree.insert(2, 1, true);
	tree.insert(3, 1, false);
	tree.insert(4, 2, true);
	tree.insert(5, 3, true);
	tree.insert(6, 3, false);
	tree.insert(7, 5, true);
	tree.insert(8, 5, false);

	tree.show();

	cout << endl;
	cout << "---------------------------------" << endl;
	cout << endl;

	tree.interchange();
	tree.show();

	return 0;
}

