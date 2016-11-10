#include <iostream>
#include <vector>
#include <queue>
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
		person* findancestor();
		void marry(person* spouse);
		void divorce();
		void givebirthto(data info);
		void showinfo();
		void check();
		void output(int blanknum);
};

person::person(data info, person* father = NULL, person* mother = NULL) {
	this->info = info;
	this->father = father;
	this->mother = mother;
	this->spouse = NULL;
}
person* person::findancestor() {	//找最早祖先
	person *p = this;
	while (p->father != NULL)
		p = p->father;
	return p;
}
void person::marry(person* spouse) {
	if (this->spouse != NULL)	//已结婚不能结婚
		return;
	if (this->spouse && this->spouse->info.male == this->info.male)		//同性不能结婚
		return;
	this->spouse = spouse;
	spouse->spouse = this;
}
void person::divorce() {
	if (this->spouse == NULL)	//未结婚不能离婚
		return;
	this->spouse = NULL;
	spouse->spouse = NULL;			
}
void person::givebirthto(data info) {
	if (this->spouse == NULL)
		return;
	person* child = new person(info, this, this->spouse);
	this->children.push_back(child);
	this->spouse->children.push_back(child);
}
void person::showinfo() {	//输出自己相关信息
	cout << "-----------------------------" << endl;
	cout << "name: " << this->info.name << endl;
	if (this->info.male)
		cout << "sex: male" << endl;
	else
		cout << "sex: female" << endl;
	cout << "father: ";
	if (this->father != NULL)
		cout << this->father->info.name << endl;
	else
		cout << endl;
	cout << "mother: ";
	if (this->mother != NULL)
		cout << this->mother->info.name << endl;
	else
		cout << endl;
	cout << "spouse: ";
	if (this->spouse != NULL)
		cout << this->spouse->info.name << endl;
	else
		cout << endl;
	cout << "children: ";
	vector<person*>::iterator it;
	for (it = this->children.begin(); it !=  this->children.end(); it++)
		if (it == this->children.begin())
			cout << (*it)->info.name << endl;
		else
		cout << "\t  " << (*it)->info.name << endl;
	cout << endl;
	cout << "-----------------------------" << endl;
}

void person::check() { 	//统计家族总代数，总人数，各代人数
		cout << "-----------------------------" << endl;
        person* ancestor = this->findancestor();
        queue<person*> traverseQueue;
        traverseQueue.push(ancestor);
        vector<int> genetationData;
        genetationData.push_back(1);
        int i, toVisitThisFloor = 1;
        person* tempPerson;
        while (!traverseQueue.empty()) {
                tempPerson = traverseQueue.front();
                for (int j = 0; j < tempPerson->children.size(); ++j) {
                        traverseQueue.push(tempPerson->children[j]);
                }
                --toVisitThisFloor;
                traverseQueue.pop();
                if (toVisitThisFloor == 0) {
                        toVisitThisFloor = traverseQueue.size();
                        genetationData.push_back(toVisitThisFloor);
                }
        }
        int totalPeople = 0;
        for (i = 0; i < genetationData.size(); ++i)
                totalPeople += genetationData[i];
        cout << "This family has " << genetationData.size() << " generations and " << totalPeople << " people\n";
        for (i = 0; i < genetationData.size()-1; ++i)
                cout << "No." << i+1 << " generation has " << genetationData[i] << " people\n";
		cout << "-----------------------------" << endl;
}

void person::output(int blanknum) {	//递归输出男性家族成员
	for (int i = 0; i < blanknum; i++)
		cout << "   ";
	cout << "∟____" << this->info.name;
	vector<person*>::iterator it;
	for (it = this->children.begin(); it !=  this->children.end(); it++) {
		cout << "" << endl;
		(*it)->output(blanknum+2);
	}
}



vector<person*> findperson(vector<person*> ancestors, string name) {	//输出有关个人信息
        vector<person*> result;
        for (int i = 0; i < ancestors.size(); ++i) {
                queue<person*> traverseQueue;
                traverseQueue.push(ancestors[i]);
                person* tempPerson;
                while (!traverseQueue.empty()) {
                        tempPerson = traverseQueue.front();
                        if (tempPerson->info.name == name) {
                                result.push_back(tempPerson);
                        }
                        for (int j = 0; j < tempPerson->children.size(); ++j) {
                                traverseQueue.push(tempPerson->children[j]);
                        }
                        traverseQueue.pop();
                }
        }
        return result;
}

int main() {
	vector<person*> ancestors;

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
	infoson.name = "godson";
	god.givebirthto(infoson);
	data infowoman;
	infowoman.name = "woman";
	infowoman.male = false;
	person woman(infowoman);

	data infograndson;
	infograndson.name = "godgrandson";
	infograndson.male = true;
	god.children[0]->marry(&woman);
	god.children[0]->givebirthto(infograndson);

	god.showinfo();
	god.children[0]->showinfo();
	god.children[0]->children[0]->showinfo();

	god.output(0);

	cout << endl;

	god.children[0]->children[0]->check();
	god.children[0]->check();	
	god.check();

	ancestors.push_back(&god);

	vector<person*> persons;
	persons = findperson(ancestors, "godson");
	persons = findperson(ancestors, "godgrandson");
	return 0;
}
