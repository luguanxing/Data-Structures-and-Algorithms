#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 记录person的id
int idCounter = 0;

struct data {    //个人信息
    string name;
    int id;
    bool male;
    data() {
        name = "";
        id = -1;
        male = 0;
    }
};

class person {    //个人类
public:
    data info;
    person *father;
    person *mother;
    person *spouse;
    vector<person *> children;
    person(data info, person *father = NULL, person *mother = NULL);
    person *findancestor();

    void marry(person *spouse);
    void divorce();
    void givebirthto(data info);
    void showinfo();
    void check();
    void output(int blanknum);
};


person::person(data info, person *father, person *mother) {
    this->info = info;
    this->father = father;
    this->mother = mother;
    this->spouse = NULL;
}

person *person::findancestor() {    //找最早祖先
    person *p = this;
    while (p->father != NULL)
        p = p->father;
    return p;
}

void person::marry(person *spouse) {
    if (this->spouse != NULL)    //已结婚不能结婚
        return;
    if (this->spouse && this->spouse->info.male == this->info.male)        //同性不能结婚
        return;
    this->spouse = spouse;
    spouse->spouse = this;
}

void person::divorce() {
    if (this->spouse == NULL)    //未结婚不能离婚
        return;
    this->spouse = NULL;
    spouse->spouse = NULL;
}

void person::givebirthto(data info) {
    if (this->spouse == NULL)
        return;
    person *child = new person(info, this, this->spouse);
    this->children.push_back(child);
    this->spouse->children.push_back(child);
}

void person::showinfo() {    //输出自己相关信息
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
    vector<person *>::iterator it;
    for (it = this->children.begin(); it != this->children.end(); it++)
        if (it == this->children.begin())
            cout << (*it)->info.name << endl;
        else
            cout << "\t  " << (*it)->info.name << endl;
    cout << endl;
    cout << "-----------------------------" << endl;
}

void person::check() {    //统计家族总代数，总人数，各代人数
    cout << "-----------------------------" << endl;
    person *ancestor = this->findancestor();
    queue<person *> traverseQueue;
    traverseQueue.push(ancestor);
    vector<int> genetationData;
    genetationData.push_back(1);
    int i, toVisitThisFloor = 1;
    person *tempPerson;
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
    cout << "This family has " << genetationData.size()-1 << " generations and " << totalPeople << " people\n";
    for (i = 0; i < genetationData.size() - 1; ++i)
        cout << "No." << i + 1 << " generation has " << genetationData[i] << " people\n";
    cout << "-----------------------------" << endl;
}

void person::output(int blanknum) {    //递归输出男性家族成员
    for (int i = 0; i < blanknum; i++)
        cout << "   ";
    cout << "∟____" << this->info.name << '(' << this->info.id << ')';
    vector<person *>::iterator it;
    if ((*it)->info.male) {
        for (it = this->children.begin(); it != this->children.end(); it++) {
            cout << "" << endl;
            (*it)->output(blanknum + 2);
        }
    }
}


person *findPerson(person *ancestors, string name, int id) {    //输出有关个人信息

    queue<person *> traverseQueue;
    traverseQueue.push(ancestors);
    person *tempPerson;
    while (!traverseQueue.empty()) {
        tempPerson = traverseQueue.front();
        if (tempPerson->info.name == name && tempPerson->info.id == id) {
            return tempPerson;
        }
        for (int j = 0; j < tempPerson->children.size(); ++j) {
            traverseQueue.push(tempPerson->children[j]);
        }
        traverseQueue.pop();
    }
    return NULL;
}

int chooseFamily(vector<person *> &families) {
    cout << "please input the family this person belong to\n"
         << "by inputting the ancestor's name of this family\n";
    string ancestorName;
    cin >> ancestorName;
    int serialNumber = -1;
    for (int i = 0; i < families.size(); ++i) {
        if (families[i]->info.name == ancestorName) {
            serialNumber = i;
            break;
        }
    }
    return serialNumber;
}


void showOrders() {
    std::cout << "orders are as follows:\n"
              << "input 1 to create a family\n"
              << "input 2 to create a person\n"
              << "input 3 to storage a relationship of marriage \n"
              << "input 4 to find somebody's spouse \n"
              << "input 5 to show all family trees \n"
              << "input 6 to show a family tree you want\n"
              << "input 7 to show statistics of family trees"
              << "input 8 to to show orders \n"
              << "input 9 to quit the system \n";
}

int main() {
    vector<person *> families;

    showOrders();
    int order;

    while (cin >> order) {
        switch (order) {
            case 1: {
                cout << "please input the first person's name of this family tree:\n";
                data ancestorInfo;
                cin >> ancestorInfo.name;
                ancestorInfo.male = 1;
                ancestorInfo.id = idCounter++;
                person *family = new person(ancestorInfo);
                families.push_back(family);
                cout << "create family successful\n";
                break;
            }

            case 2: {
                cout << "please input the person's name "
                     << "and his sex(0 for female, 1 for male):\n";
                data tempInfo;
                tempInfo.id = idCounter++;
                cin >> tempInfo.name >> tempInfo.male;
                cout << "please input name and id of father:\n";
                string fatherName;
                int fatherId;
                cin >> fatherName >> fatherId;
                int serialNumber = chooseFamily(families);
                if (serialNumber == -1) {
                    cout << "can't find this family\n";
                    continue;
                }

                person *father = findPerson(families[serialNumber], fatherName, fatherId);
                if (father == NULL) {
                    cout << "can't find father\n";
                    continue;
                }
                father->givebirthto(tempInfo);
                cout << "create person successful\n";
                break;
            }
            case 3: {
                cout << "please input the bridegroom's name and id:\n";
                string bridgegroomName, bridgeName;
                int bridgeFamilyNumber, brdgegroomFamilyNumber;
                int bridgegroomId, bridgeId;
                cin >> bridgegroomName >> bridgegroomId;
                brdgegroomFamilyNumber = chooseFamily(families);
                if (brdgegroomFamilyNumber == -1) {
                    cout << "can't find brdgegroom's family\n";
                    continue;
                }
                person *bridgegroom = findPerson(families[brdgegroomFamilyNumber],
                                                 bridgegroomName, bridgegroomId);
                if (bridgegroom == NULL) {
                    cout << "can't find bridgegroom\n";
                    continue;
                }

                cout << "please input the bride's name and id:\n";
                cin >> bridgeName >> bridgeId;
                bridgeFamilyNumber = chooseFamily(families);
                if (bridgeFamilyNumber == -1) {
                    cout << "can't find bridge's family\n";
                    continue;
                }
                person *bridge = findPerson(families[bridgeFamilyNumber],
                                            bridgeName, bridgeId);
                if (bridge == NULL) {
                    cout << "can't find bridge\n";
                    continue;
                }
                bridgegroom->marry(bridge);
                cout << "create relationship successful\n";
                break;
            }

            case 4: {
                cout << "please input the person's name and id:\n";
                string tempPersonName;
                int tempPersonFamilyNumber, tempPersonId;
                cin >> tempPersonName >> tempPersonId;
                tempPersonFamilyNumber = chooseFamily(families);
                if (tempPersonFamilyNumber == -1) {
                    cout << "can't find the person's family\n";
                    continue;
                }
                person *tempPerson = findPerson(families[tempPersonFamilyNumber],
                                                tempPersonName, tempPersonId);
                if (tempPerson == NULL) {
                    cout << "can't find tempPerson\n";
                    continue;
                }
                tempPerson->spouse->showinfo();
                break;
            }

            case 5: {
                for (int i = 0; i < families.size(); ++i) {
                    cout << families[i]->info.name << "'s family tree:\n";
                    families[i]->output(2);
                }
                break;
            }

            case 6: {
                int queryFamilyNumber;
                queryFamilyNumber = chooseFamily(families);
                if (queryFamilyNumber == -1) {
                    cout << "can't find this family\n";
                    continue;
                }
                families[queryFamilyNumber]->output(2);
                break;
            }

            case 7: {
                int queryFamilyNumber1;
                queryFamilyNumber1 = chooseFamily(families);
                if (queryFamilyNumber1 == -1) {
                    cout << "can't find this family\n";
                    continue;
                }
                families[queryFamilyNumber1]->check();
                break;
            }

            case 8: {
                showOrders();
                break;
            }

            case 9: {
                exit(1);
            }

            default: {
                cout << "please input correct order:\n";
                break;
            }
        }
    }
}


/*int main() {
    vector<person *> ancestors;
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
    infoson.name = "godson2";
    god.givebirthto(infoson);
    infoson.name = "godsony";
    god.givebirthto(infoson);
    infoson.name = "godsonj";
    god.givebirthto(infoson);
    infoson.name = "godsonx";
    god.givebirthto(infoson);
    infoson.name = "godson";
    god.givebirthto(infoson);
    data infowoman;
    infowoman.name = "woman";
    infowoman.male = false;
    person woman(infowoman);
    infowoman.name = "woman2";
    person woman2(infowoman);
    data infograndson;
    infograndson.name = "godgrandson";
    infograndson.male = true;
    god.children[0]->marry(&woman);
    god.children[0]->givebirthto(infograndson);
    infograndson.name = "godgrandson2";
    god.children[1]->marry(&woman2);
    god.children[1]->givebirthto(infograndson);
    infograndson.name = "godgrandsonkk";
    god.children[1]->givebirthto(infograndson);
    god.children[0]->children[0]->check();
    god.children[0]->check();
    god.check();
    god.output(0);
    cout << endl;
    ancestors.push_back(&god);
    vector<person *> persons;
    persons = findperson(ancestors, "godson");
    persons = findperson(ancestors, "godgrandson");
    god.showinfo();
    god.children[1]->showinfo();
    god.children[0]->children[0]->showinfo();
    return 0;
}*/
