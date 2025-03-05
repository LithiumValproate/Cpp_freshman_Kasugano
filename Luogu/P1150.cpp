#include <iostream>
using namespace std;
int main() {
    int n, k, b = 0, ans = 0;
    cin >> n >> k;
    while (n != 0) {
        n--;
        b++;
        if (b == k) {
            n++;
            b = 0;
        }
        ans++;
    }
    cout << ans;
    return 0;
}