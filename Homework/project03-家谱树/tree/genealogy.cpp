#include <iostream>
#include <vector>
#include <string>
using namespace std;

class data {	//������Ϣ
	public:
		string name;
		bool male;
};

class person {	//������
	public:
		data info;

		person* father;
		person* mother;
		person* spouse;
		vector<person*> children;

		person(data info, person* father, person* mother);
		void marry(person* spouse);
		void divorce();
		void givebirthto();
		void givebirthto(data info);
		void showinfo();
		void check();
};

person::person(data info, person* father = NULL, person* mother = NULL) {
	this->info = info;
	this->father = father;
	this->mother = mother;
	this->spouse = NULL;
}
void person::marry(person* spouse) {
	if (this->spouse != NULL)	//�ѽ�鲻�ܽ��
		return;
	if (this->spouse->info.male == this->info.male)		//ͬ�Բ��ܽ��
		return;
	this->spouse = spouse;
	spouse->spouse = this;
}
void person::divorce() {
	this->spouse = NULL;
	spouse->spouse = NULL;			
}
void person::givebirthto() {
	if (this->father == NULL || this->mother  == NULL)	//�޷�һ���˵õ����
		return;
	data info;
	bool male;
	string name;
	cin >> name >> male;
	info.name = name;
	info.male = male;
	person* child = new person(info, this, this->spouse);
	children.push_back(child);
}
void person::givebirthto(data info) {
	person* child = new person(info, this, this->spouse);
	this->children.push_back(child);
	this->spouse->children.push_back(child);
}
void person::showinfo();	//����Լ������Ϣ
void person::check();	//ͳ�Ƽ����ܴ���������������������



person* findperson(string name);	//����йظ�����Ϣ
person* findancestor(string name);	//��ĳ������
void output();	//�ݹ�������Լ����Ա

int main() {
	
/*
	data info;
	info.name = "god";
	info.male = true;
	person god(info);

	data infowife;
	infowife.name = "godwife";
	infowife.male = false;
	person godwife(infowife);

	data infoson;
	infoson.name = "godson";
	infoson.male = true;


	god.marry(&godwife);
	god.givebirthto(infoson);
*/

	return 0;
}