#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <variant>
using namespace std;
using us = unsigned short;
using KeyType = variant<us, string>;

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

auto equalKey = [](const Profile* p, const KeyType& key) -> bool {
    return holds_alternative<us>(key) ? (p->id == get<us>(key)) : (p->name == get<string>(key));
};

Profile* find(Profile* head, const KeyType& key) {
    for (Profile* tmp = head; tmp != nullptr; tmp = tmp->next) {
        if (equalKey(tmp, key))
            return tmp;
    }
    return nullptr;
}

void add(Profile* head, us& n) {
    Profile* tmp = head;
    while (tmp->next != nullptr)
        tmp = tmp->next;
    Profile* neo = new Profile;
    cout << "Enter data (Name, Sex, Birthdate(YYYY MM DD)):\n";
    cin >> neo->name >> neo->sex >> neo->year >> neo->month >> neo->date;
    neo->id = ++n;
    neo->age = 2025 - neo->year;
    neo->next = nullptr;
    tmp->next = neo;
    cout << "Profile added.\n";
}

void search(Profile* head, const KeyType& key) {
    Profile* tmp = find(head, key);
    if (tmp == nullptr) {
        cout << "Not found.\n";
        return;
    }
    printf("ID: %hu, Name: %s, Sex: %c, Birthdate: %hu-%hu-%hu, Age: %hu\n",
           tmp->id, tmp->name.c_str(), tmp->sex, tmp->year, tmp->month, tmp->date, tmp->age);
}

void edit(Profile* head, const KeyType& key) {
    Profile* tmp = find(head, key);
    if (tmp == nullptr) {
        cout << "Not found.\n";
        return;
    }
    cout << "Enter a number corresponding to the type of data to edit\n"
         << "1. Name\t2. Sex\t3. Birthdate\n";
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
        cout << "Enter new birthdate (YYYY MM DD): ";
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
    cout << "Profile edited.\n";
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
    return (order == 2) ? !result : result;
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
    if (!head)
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
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    for (Profile* tmp = head; tmp != nullptr; tmp = tmp->next) {
        printf("ID: %hu, Name: %s, Sex: %c, Birthdate: %hu-%hu-%hu, Age: %hu\n",
               tmp->id, tmp->name.c_str(), tmp->sex, tmp->year, tmp->month, tmp->date, tmp->age);
    }
}

void del(Profile*& head, const KeyType& key) {
    if (!head)
        return;
    if (equalKey(head, key)) {
        Profile* temp = head;
        head = head->next;
        delete temp;
        cout << "Profile deleted.\n";
        return;
    }
    Profile* current = head;
    while (current->next != nullptr && !equalKey(current->next, key))
        current = current->next;
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
            cout << "Enter ID or name to search\n";
            string input;
            cin >> input;
            KeyType sKey = all_of(input.begin(), input.end(), ::isdigit)
                               ? KeyType(static_cast<us>(stoi(input)))
                               : KeyType(input);
            search(head, sKey);
            break;
        }
        case 3: {
            cout << "Enter ID or name to edit\n";
            string input;
            cin >> input;
            KeyType eKey = all_of(input.begin(), input.end(), ::isdigit)
                               ? KeyType(static_cast<us>(stoi(input)))
                               : KeyType(input);
            edit(head, eKey);
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
            cout << "Enter ID or name to delete\n";
            string input;
            cin >> input;
            KeyType dKey = all_of(input.begin(), input.end(), ::isdigit)
                               ? KeyType(static_cast<us>(stoi(input)))
                               : KeyType(input);
            del(head, dKey);
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
         << "Name, Sex, Birthdate(YYYY MM DD)\n";
    cin >> head->name >> head->sex >> head->year >> head->month >> head->date;
    head->id = n;
    head->age = 2025 - head->year;
    head->next = nullptr;
    select_func(head, n);
    while (head) {
        Profile* tmp = head;
        head = head->next;
        delete tmp;
    }
    system("pause");
    return 0;
}