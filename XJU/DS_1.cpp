#include <iostream>
#include <string>
using namespace std;
using us = unsigned short;
struct Profile {
    us id;
    string name;
    char sex;
    us year;
    us month;
    us date;
    short age = 2025 - year;
    Profile* next;
};

void add(Profile*& pre, Profile* neo) {
    pre->next = neo;
    
}

int main() {
    cout << "Null\n"
         << "Enter data of a new profile.\n"
         << "Name\tSex\tBirthdate";
    Profile* head;
    us n = 1;
    cin >> head.name >> head.sex >> head.year >> head.month >> head.date;
    head->id = n;
    head->next = nullptr;
    
}