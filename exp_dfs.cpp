#include <bits/stdc++.h>

using namespace std;
long long ans[101];

long long dfs(int x) {
    if (ans[x] != 0) return ans[x];
    if (x <= 2) return 1;
    else return ans[x] = dfs(x - 1) + dfs(x - 2);
}

int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        int a;
        cin >> a;
        cout << dfs(a) << endl;
    }
    return 0;
}
