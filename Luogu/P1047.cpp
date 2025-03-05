#include <iostream>
using namespace std;
int main() {
    int l, m;
    cin >> l >> m;
    int u[m], v[m], t[l + 1];
    for (int i = 0; i <= l; i++)
        t[i] = 1;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        for (int j = u[i]; j <= v[i]; j++)
            t[j] = 0;
    }
    int ans = 0;
    for (int i = 0; i <= l; i++)
        ans += t[i];
    cout << ans;
    return 0;
}