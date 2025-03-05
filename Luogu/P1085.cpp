#include <iostream>
using namespace std;
int main() {
    int a, b, s = 0;
    int ans = s;
    for (int i = 1; i < 8; i++) {
        cin >> a >> b;
        if (a + b > s && a + b > 7) {
            s = a + b;
            ans = i;
        }
    }
    cout << ans;
    return 0;
}