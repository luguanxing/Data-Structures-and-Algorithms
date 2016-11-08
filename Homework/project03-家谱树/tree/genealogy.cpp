#include <iostream>
#include <vector>
#include <string>
using namespace std;

class data {	//个人信息
	public:
		string name;
		bool male;
};

class person {	//个人类
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
	if (this->spouse != NULL)	//已结婚不能结婚
		return;
	if (this->spouse->info.male == this->info.male)		//同性不能结婚
		return;
	this->spouse = spouse;
	spouse->spouse = this;
}
void person::divorce() {
	this->spouse = NULL;
	spouse->spouse = NULL;			
}
void person::givebirthto() {
	if (this->father == NULL || this->mother  == NULL)	//无法一个人得到后代
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
void person::showinfo();	//输出自己相关信息
void person::check();	//统计家族总代数，总人数，各代人数



person* findperson(string name);	//输出有关个人信息
person* findancestor(string name);	//找某人祖先
void output();	//递归输出男性家族成员

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