#include <iostream>
using namespace std;
int main() {
    int a[8], b[8], ans = 0;
    a[0] = b[0] = 0;
    for (int i = 1; i < 8; i++) {
        cin >> a[i]>> b[i];
        if (a[i] + b[i] > 8 && a[i] + b[i] > a[ans] + b[ans])
            ans = i;
    }
    cout << ans;
    return 0;
}