#include <iostream>
#include <string>

using us =  unsigned short;
using namespace std;
struct Employee {
    us id;
    string name;
    string sex;
    string ethnicity;
    struct date {
        us year;
        us month;
        us day;
    };
    date hire_date;
    string position;
    Employee* next;
} ZhangSan, MaXiaoqing, Mehmet, Heyssar, Bahadda;

Employee* create() {
    return nullptr;
}

void select(Employee*& head);

void insert(Employee*& head, Employee* newNode) {
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Employee* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
}

void del(Employee*& head, us empId) {
    Employee* prev = head;
    while (prev->next->id != empId)
        prev = prev->next;
    if (prev->next != nullptr) {
        Employee* temp = prev->next;
        prev->next = temp->next;
        delete temp;
    }
    else
        cout << "无效的ID。";
}

void update(Employee*& head, us empId, us dataId) {
    Employee* temp = head;
    while (temp->id != empId)
        temp = temp->next;
    us year, month, day;
    string name, sex, ethnicity, position;
    switch (dataId) {
        case 1: {
            cin >> name;
            temp->name = name;
            break;
        }
        case 2: {
            cin >> sex;
            temp->sex = sex;
            break;
        }
        case 3: {
            cin >> ethnicity;
            temp->ethnicity = ethnicity;
            break;
        }
        case 4: {
            cin >> year >> month >> day;
            temp->hire_date = {year, month, day};
            break;
        }
        case 5: {
            cin >> position;
            temp->position = position;
            break;
        }
        case 6: {
            select(head);
            break;
        }
        default: {
            cout << "无效的选择" << endl;
            break;
        }
    }
}

void search(Employee* head, us empId) {
    Employee* temp = head;
    while (temp->id != empId) {
        temp = temp->next;
        if (temp->next == nullptr)
            break;
    }
    if (temp->id == empId) {
        cout << "姓名：" << temp->name << endl;
        cout << "性别：" << temp->sex << endl;
        cout << "民族：" << temp->ethnicity << endl;
        cout << "入职日期：" << temp->hire_date.year << "年" << temp->hire_date.month << "月" << temp->hire_date.day
             << "日" << endl;
        cout << "职位：" << temp->position << endl;
    }
    else
        cout << "无效的ID" << endl;
}

void travel(Employee* head) {
    Employee* temp = head;
    while (temp != nullptr) {
        cout << "员工ID: " << temp->id << endl;
        cout << "姓名：" << temp->name << endl;
        cout << "性别：" << temp->sex << endl;
        cout << "民族：" << temp->ethnicity << endl;
        cout << "入职日期：" << temp->hire_date.year << "年" << temp->hire_date.month << "月" << temp->hire_date.day
             << "日" << endl;
        cout << "职位：" << temp->position << endl;
        temp = temp->next;
    }
}

int main() {
    Employee* head = create();
    ZhangSan = {1, "张三", "男", "汉族", {2000, 9, 28}, "处长"};
    MaXiaoqing = {2, "马晓晴", "女", "回族", {2000, 5, 3}, "科长"};
    Mehmet = {3, "买买提", "男", "维吾尔族", {2007, 7, 14}, "职员"};
    Heyssar = {4, "海萨尔", "男", "哈萨克族", {2004, 6, 23}, "职员"};
    Bahadda = {5, "白哈达", "男", "蒙古族", {2009, 7, 6}, "科长"};
    insert(head, &ZhangSan);
    insert(head, &MaXiaoqing);
    insert(head, &Mehmet);
    insert(head, &Heyssar);
    insert(head, &Bahadda);
    select(head);
    return 0;
}

void select(Employee*& head) {
    int choice;
    do {
        cout << "选择您要执行的操作：" << endl;
        cout << "1. 插入" << endl;
        cout << "2. 删除" << endl;
        cout << "3. 更新" << endl;
        cout << "4. 搜索" << endl;
        cout << "5. 遍历" << endl;
        cout << "6. 退出" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                us id, year, month, day;
                string name, sex, ethnicity, position;
                cout << "请输入员工ID，姓名，性别，民族，入职年月日，职位：" << endl;
                cin >> id >> name >> sex >> ethnicity >> year >> month >> day >> position;
                Employee* newEmployee = new Employee{id, name, sex, ethnicity, {year, month, day}, position};
                insert(head, newEmployee);
                break;
            }
            case 2: {
                us id;
                cout << "输入您想删除的员工的ID:";
                cin >> id;
                del(head, id);
                break;
            }
            case 3: {
                us id, choice2;
                cout << "请输入要更改的员工ID:";
                cin >> id;
                cout << "请选择要更改的数据类型：" << endl;
                cout << "1. 姓名" << endl;
                cout << "2. 性别" << endl;
                cout << "3. 民族" << endl;
                cout << "4. 入职日期" << endl;
                cout << "5. 职位" << endl;
                cout << "6. 返回" << endl;
                cin >> choice2;
                cout << "请输入更改后的内容：" << endl;
                update(head, id, choice2);
                break;
            }
            case 4: {
                us id;
                cout << "请输入要查询的员工ID：";
                cin >> id;
                search(head, id);
                break;
            }
            case 5: {
                travel(head);
                break;
            }
            case 6: {
                cout << "退出中..." << endl;
                break;
            }
            default: {
                cout << "无效的选择。" << endl;
                break;
            }
        }
    } while (choice != 6);
}