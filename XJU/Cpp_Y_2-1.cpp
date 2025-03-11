#include <iostream>
using namespace std;
int max_func(int& a, int& b, int& c) {
    int ans = a;
    if (ans < b) {
        ans = b;
        if (ans < c)
            ans = c;
    }
    return ans;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max_func(a, b, c) << endl;
    system("pause");
    return 0;
}