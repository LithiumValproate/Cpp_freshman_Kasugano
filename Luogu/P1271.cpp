#include <iostream>
using namespace std;
void f(int p[], int m, int n) {
    int count[n] = {0};
    for (int i = 0; i < m; i++)
        count[p[i] - 1]++;
    for (int i = 0; i < n; i++) {
        if (count[i] == 0)
            continue;
        for (int j = 0; j < count[i]; j++)
            cout << i + 1 << ' ';
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int p[m];
    for (int i = 0; i < m; i++)
        cin >> p[i];
    f(p, m, n);
    system("pause");
    return 0;
}