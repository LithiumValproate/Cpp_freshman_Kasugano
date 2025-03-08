#include <iomanip>
#include <iostream>
using namespace std;
const double PI = 3.14159;
int main() {
    cout << "Please enter the number corresponding to the shape you chose:\n"
         << "1. Rectangle\n2. Circle" << endl;
    int c;
    cin >> c;
    cout << fixed << setprecision(2);
    switch (c) {
    case 1:
        cout << "Enter the length and width of the rectangle:\n";
        double a, b;
        cin >> a >> b;
        cout << "The circumference is " << (a + b) * 2 << endl
             << "The area is " << a * b << endl;
        break;
    case 2:
        cout << "Enter the radius of the circle\n";
        double r;
        cin >> r;
        cout << "The circumference is " << r * 2 * PI << endl
             << "The area is " << r * r * PI << endl;
        break;
    default:
        break;
    }
    system("pause");
    return 0;
}