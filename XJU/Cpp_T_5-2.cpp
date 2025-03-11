#include <iomanip>
#include <iostream>
#define INPUT(x, n)             \
    for (int i = 0; i < n; i++) \
        cin >> x[i];
using namespace std;
float avr(float x[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += x[i];
    return sum / n;
}
int main() {
    float a[10], b[7];
    INPUT(a, 10);
    INPUT(b, 7);
    cout << fixed << setprecision(2);
    cout << "Average score of Class A is " << avr(a, 10) << endl
         << "Average score of Class B is " << avr(b, 7) << endl;
    system("pause");
    return 0;
}
