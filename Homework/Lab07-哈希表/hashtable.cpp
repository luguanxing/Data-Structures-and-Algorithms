#include <iostream>
#include <string>
using namespace std;


#define HASH_MAXSIZE 85

class Student{
	public:
		int id;
		bool sex;
		string name;
		string phone;
	public:
		Student() {
			this->id = 0;
			this->sex = false;
			this->name = "undefined";
			this->phone = "undefined";
		}
		void print() {
			cout << "学号:" <<this->id << "\t性别:" << 	this->sex <<  "\t姓名:" << this->name <<  "\t电话:" << this->phone << endl;
		}
};


class HashTable {  
	public:  
		Student students[HASH_MAXSIZE];   
		int size;
	public:  
		HashTable();
		void Show();
		int Linercheck(int key);
		int Findstudent(int id);
		void Hashcreate(Student &student);   
		void Hashdelete(int id);   
};

HashTable::HashTable() {  
	size = 0;
} 

void HashTable::Show() {
	for (int i = 0; i < HASH_MAXSIZE; i++)
		if (students[i].id)
			students[i].print();
}

int HashTable::Linercheck(int id) {	//线性探测处理冲突,id是探测时的哈希表关键码, 成功处理冲突返回新的关键码未进行冲突处理,失败返回-1
	int ct = 0;
	for (int i = id % HASH_MAXSIZE; ct < HASH_MAXSIZE; i++, ct++)
		if (students[i % HASH_MAXSIZE].id == 0)
			return i % HASH_MAXSIZE;
    return -1;
}

int HashTable::Findstudent(int id) {	//以id为关键字查找，失败返回-1
	int ct = 0;
	for (int i = id % HASH_MAXSIZE; ct < HASH_MAXSIZE; i++, ct++)
		if (students[i % HASH_MAXSIZE].id == id)
			return i % HASH_MAXSIZE;
	return -1;
}

void HashTable::Hashcreate(Student &student) {	//以id为关键字，先检测冲突，后建立哈希数据  
	int result = Linercheck(student.id);
	if (result != -1) {
		students[result].id = student.id;
		students[result].name = student.name;
		students[result].phone = student.phone;
		students[result].sex = student.sex;
		size++;
		cout << "创建成功!" << endl;
	} else {
		cout << "创建失败!" << endl;
	}
}

void HashTable::Hashdelete(int id) {	//以id为关键字删除数据
	for (int i = id; i < HASH_MAXSIZE; i++)
		if (students[i % HASH_MAXSIZE].id == id) {
			students[i % HASH_MAXSIZE].id = 0;
			students[i % HASH_MAXSIZE].sex = false;
			students[i % HASH_MAXSIZE].name = "undefined";
			students[i % HASH_MAXSIZE].phone = "undefined";
			size--;
			cout << "删除成功!" << endl;
			return;
		}
	cout << "删除失败!" << endl;
}


void showhelp() {
	cout << "------------------------------" << endl;
	cout << "输入数字选择功能" << endl;
	cout << "0.帮助" << endl;
	cout << "1.创建学生" << endl;
	cout << "2.删除学生" << endl;
	cout << "3.查找学生" << endl;
	cout << "4.显示所有" << endl;
	cout << "5.退出" << endl;
	cout << "------------------------------" << endl;
}



int main() {
	HashTable hashtable;

	for (int i = 0; i < 80; i++) {	//创造80个 学生数据
				int id = i;
				bool sex = true;
				char namebuff[10];
				sprintf(namebuff, "student%d", i);
				string name = namebuff;
				char phonebuff[10];
				sprintf(phonebuff, "000000%d", i);
				string phone = phonebuff;
    
				Student newone;
				newone.id = id;
				newone.sex = sex;
				newone.name = name;
				newone.phone = phone;
    
				hashtable.Hashcreate(newone);
	}

	showhelp();
	while (true) {
		int cmd;
		cin >> cmd;
		switch (cmd) {
			case 0: {
				showhelp();
			} break;

			case 1: {
				int id;
				bool sex;
				string name;
				string phone;

				cout << "学号:";
				cin >> id;
				cout << "性别:(0女1男)";
				cin >> sex;
				cout << "姓名:";
				cin >> name;
				cout << "电话:";
				cin >> phone;

				Student newone;
				newone.id = id;
				newone.sex = sex;
				newone.name = name;
				newone.phone = phone;

				hashtable.Hashcreate(newone);
			} break;

			case 2: {
				int id;
				cout << "学号:";
				cin >> id;

				hashtable.Hashdelete(id);
			} break;

			case 3: {
				int id;
				cout << "学号:";
				cin >> id;
	
				int result = hashtable.Findstudent(id);
				if (result == -1)
					cout << "失败" << endl;
				else
					hashtable.students[result].print();
			} break;

			case 4: {
					hashtable.Show();
			} break;

			case 5: {
					exit(0);
			} break;
			default:
				cout << "未知指令" << endl;
		}
	}
	return 0;
}
