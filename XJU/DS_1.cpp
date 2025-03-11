#include <iostream>
#include <string>
#include <variant>
using namespace std;
using us = unsigned short;

struct Profile {
    us id;
    string name;
    char sex;
    us year;
    us month;
    us date;
    us age;
    Profile* next;
};

Profile* find(Profile* head, const variant<us, string>& key) {
    Profile* tmp = head;
    if (holds_alternative<us>(key)) {
        us k = get<us>(key);
        while (tmp != nullptr && tmp->id != k)
            tmp = tmp->next;
    } else {
        string k = get<string>(key);
        while (tmp != nullptr && tmp->name != k)
            tmp = tmp->next;
    }
    return tmp;
}

void add(Profile* head, us& n) {
    Profile* tmp = head;
    while (tmp->next != nullptr)
        tmp = tmp->next;
    Profile* neo = new Profile;
    cout << "Enter data (Name Sex Year Month Date):\n";
    cin >> neo->name >> neo->sex >> neo->year >> neo->month >> neo->date;
    neo->id = ++n;
    neo->age = 2025 - neo->year;
    neo->next = nullptr;
    tmp->next = neo;
}

void search(Profile* head, const variant<us, string>& key) {
    Profile* tmp = find(head, key);
    if (tmp == nullptr) {
        cout << "Not found.\n";
        return;
    }
    printf("ID: %hu\nName: %s\nSex: %c\nBirthdate: %hu-%hu-%hu\nAge: %hu\n",
           tmp->id, tmp->name.c_str(), tmp->sex, tmp->year, tmp->month, tmp->date, tmp->age);
}

void edit(Profile* head, const variant<us, string>& key) {
    Profile* tmp = find(head, key);
    if (tmp == nullptr) {
        cout << "Not found.\n";
        return;
    }
    cout << "Enter a number corresponding to the type of data to edit\n"
         << "1. Name\n"
         << "2. Sex\n"
         << "3. Birthdate\n";
    us s;
    cin >> s;
    switch (s) {
    case 1: {
        string newName;
        cout << "Enter new name: ";
        cin >> newName;
        tmp->name = newName;
        break;
    }
    case 2: {
        char newSex;
        cout << "Enter new sex: ";
        cin >> newSex;
        tmp->sex = newSex;
        break;
    }
    case 3: {
        us newY, newM, newD;
        cout << "Enter new birthdate (Year Month Date): ";
        cin >> newY >> newM >> newD;
        tmp->year = newY;
        tmp->month = newM;
        tmp->date = newD;
        tmp->age = 2025 - newY;
        break;
    }
    default:
        cout << "Invalid\n";
        break;
    }
}

bool compare(Profile* a, Profile* b, us c, us order) {
    bool result;
    switch (c) {
    case 1:
        result = a->id < b->id;
        break;
    case 2:
        result = a->name < b->name;
        break;
    case 3:
        result = a->sex < b->sex;
        break;
    case 4:
        result = a->age < b->age;
        break;
    default:
        result = true;
        break;
    }
    if (order == 2)
        return !result;
    else
        return result;
}

void swap_data(Profile* a, Profile* b) {
    swap(a->id, b->id);
    swap(a->name, b->name);
    swap(a->sex, b->sex);
    swap(a->year, b->year);
    swap(a->month, b->month);
    swap(a->date, b->date);
    swap(a->age, b->age);
}

void sort_p(Profile* head, us c, us order) {
    if (head == nullptr)
        return;
    bool swapped;
    do {
        swapped = false;
        Profile* current = head;
        while (current->next != nullptr) {
            if (!compare(current, current->next, c, order)) {
                swap_data(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
    cout << "List sorted.\n";
}

void check(Profile* head) {
    Profile* tmp = head;
    if (tmp == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    while (tmp != nullptr) {
        printf("ID: %hu, Name: %s, Sex: %c, Birthdate: %hu-%hu-%hu, Age: %hu\n",
               tmp->id, tmp->name.c_str(), tmp->sex, tmp->year, tmp->month, tmp->date, tmp->age);
        tmp = tmp->next;
    }
}

void del(Profile*& head, const variant<us, string>& key) {
    if (head == nullptr)
        return;
    bool matchHead = false;
    if (holds_alternative<us>(key))
        matchHead = (head->id == get<us>(key));
    else
        matchHead = (head->name == get<string>(key));
    if (matchHead) {
        Profile* temp = head;
        head = head->next;
        delete temp;
        cout << "Profile deleted.\n";
        return;
    }
    Profile* current = head;
    while (current->next != nullptr) {
        bool match = false;
        if (holds_alternative<us>(key))
            match = (current->next->id == get<us>(key));
        else
            match = (current->next->name == get<string>(key));
        if (match)
            break;
        current = current->next;
    }
    if (current->next != nullptr) {
        Profile* temp = current->next;
        current->next = temp->next;
        delete temp;
        cout << "Profile deleted.\n";
    } else {
        cout << "Not found.\n";
    }
}

void select_func(Profile*& head, us& n) {
    while (true) {
        cout << "Enter a number to select a function.\n"
             << "1. Add a profile\n"
             << "2. Search a profile\n"
             << "3. Edit a profile\n"
             << "4. Sort the list\n"
             << "5. Check the list\n"
             << "6. Delete a profile\n"
             << "7. Exit\n";
        int a;
        cin >> a;
        switch (a) {
        case 1:
            add(head, n);
            break;
        case 2: {
            cout << "Enter a number to select a filter.\n"
                 << "1. ID\n"
                 << "2. Name\n";
            int b;
            cin >> b;
            if (b == 1) {
                us sId;
                cout << "Enter ID: ";
                cin >> sId;
                search(head, sId);
            } else if (b == 2) {
                string sName;
                cout << "Enter Name: ";
                cin >> sName;
                search(head, sName);
            } else {
                cout << "Invalid\n";
            }
            break;
        }
        case 3: {
            cout << "Enter a number to select a filter.\n"
                 << "1. ID\n"
                 << "2. Name\n";
            int c;
            cin >> c;
            if (c == 1) {
                us eId;
                cout << "Enter ID: ";
                cin >> eId;
                edit(head, eId);
            } else if (c == 2) {
                string eName;
                cout << "Enter Name: ";
                cin >> eName;
                edit(head, eName);
            } else {
                cout << "Invalid\n";
            }
            break;
        }
        case 4: {
            cout << "Sort by...\n"
                 << "1. ID\n"
                 << "2. Name\n"
                 << "3. Sex\n"
                 << "4. Age\n";
            us d;
            cin >> d;
            cout << "1. Ascending\n2. Descending\n";
            us e;
            cin >> e;
            sort_p(head, d, e);
            break;
        }
        case 5:
            check(head);
            break;
        case 6: {
            cout << "Enter a number to select a filter.\n"
                 << "1. ID\n"
                 << "2. Name\n";
            int f;
            cin >> f;
            if (f == 1) {
                us dId;
                cout << "Enter ID: ";
                cin >> dId;
                del(head, dId);
            } else if (f == 2) {
                string dName;
                cout << "Enter Name: ";
                cin >> dName;
                del(head, dName);
            } else {
                cout << "Invalid\n";
            }
            break;
        }
        case 7:
            return;
        default:
            cout << "Invalid\n";
            break;
        }
    }
}

int main() {
    Profile* head = new Profile;
    us n = 1;
    cout << "Enter data of a new profile.\n"
         << "Name\tSex\tYear Month Date\n";
    cin >> head->name >> head->sex >> head->year >> head->month >> head->date;
    head->id = n;
    head->age = 2025 - head->year;
    head->next = nullptr;
    select_func(head, n);
    while (head) {
        Profile* temp = head;
        head = head->next;
        delete temp;
    }
    system("pause");
    return 0;
}