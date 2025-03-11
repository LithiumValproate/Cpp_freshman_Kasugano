#include <cmath>
#include <iostream>
using namespace std;
int a, x, n;
long long func(int a, int x, int n) {
    return a * pow(x, n) + exp(2);
}
int main() {
    cin >> a >> x >> n;
    cout << func(a, x, n) << endl;
    system("pause");
    return 0;
}