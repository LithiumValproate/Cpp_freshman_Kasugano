#include <iostream>
using namespace std;
long long ans = 0;
int f(int m, int a[], int n) {
    for (int i = n; i >= 0; i--) {
        int cost = a[i] + f(m, a[], i - 1);
        if (cost == m) {
            ans++;
            continue;
        }
        return cost;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    f(m, a, n);
    cout << ans;
    return 0;
}