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
			cout << "ѧ��:" <<this->id << "\t�Ա�:" << 	this->sex <<  "\t����:" << this->name <<  "\t�绰:" << this->phone << endl;
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

int HashTable::Linercheck(int id) {	//����̽�⴦���ͻ,id��̽��ʱ�Ĺ�ϣ��ؼ���, �ɹ������ͻ�����µĹؼ���δ���г�ͻ����,ʧ�ܷ���-1
	int ct = 0;
	for (int i = id % HASH_MAXSIZE; ct < HASH_MAXSIZE; i++, ct++)
		if (students[i % HASH_MAXSIZE].id == 0)
			return i % HASH_MAXSIZE;
    return -1;
}

int HashTable::Findstudent(int id) {	//��idΪ�ؼ��ֲ��ң�ʧ�ܷ���-1
	int ct = 0;
	for (int i = id % HASH_MAXSIZE; ct < HASH_MAXSIZE; i++, ct++)
		if (students[i % HASH_MAXSIZE].id == id)
			return i % HASH_MAXSIZE;
	return -1;
}

void HashTable::Hashcreate(Student &student) {	//��idΪ�ؼ��֣��ȼ���ͻ��������ϣ����  
	int result = Linercheck(student.id);
	if (result != -1) {
		students[result].id = student.id;
		students[result].name = student.name;
		students[result].phone = student.phone;
		students[result].sex = student.sex;
		size++;
		cout << "�����ɹ�!" << endl;
	} else {
		cout << "����ʧ��!" << endl;
	}
}

void HashTable::Hashdelete(int id) {	//��idΪ�ؼ���ɾ������
	for (int i = id; i < HASH_MAXSIZE; i++)
		if (students[i % HASH_MAXSIZE].id == id) {
			students[i % HASH_MAXSIZE].id = 0;
			students[i % HASH_MAXSIZE].sex = false;
			students[i % HASH_MAXSIZE].name = "undefined";
			students[i % HASH_MAXSIZE].phone = "undefined";
			size--;
			cout << "ɾ���ɹ�!" << endl;
			return;
		}
	cout << "ɾ��ʧ��!" << endl;
}


void showhelp() {
	cout << "------------------------------" << endl;
	cout << "��������ѡ����" << endl;
	cout << "0.����" << endl;
	cout << "1.����ѧ��" << endl;
	cout << "2.ɾ��ѧ��" << endl;
	cout << "3.����ѧ��" << endl;
	cout << "4.��ʾ����" << endl;
	cout << "5.�˳�" << endl;
	cout << "------------------------------" << endl;
}



int main() {
	HashTable hashtable;

	for (int i = 0; i < 180; i++) {	//����180�� ѧ������
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

				cout << "ѧ��:";
				cin >> id;
				cout << "�Ա�:(0Ů1��)";
				cin >> sex;
				cout << "����:";
				cin >> name;
				cout << "�绰:";
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
				cout << "ѧ��:";
				cin >> id;

				hashtable.Hashdelete(id);
			} break;

			case 3: {
				int id;
				cout << "ѧ��:";
				cin >> id;
	
				int result = hashtable.Findstudent(id);
				if (result == -1)
					cout << "ʧ��" << endl;
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
				cout << "δָ֪��" << endl;
		}
	}
	return 0;
}