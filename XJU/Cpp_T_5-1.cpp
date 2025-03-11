#include <array>
#include <iostream>
using namespace std;
array<int, 2> max_func(int a[], int n) {
    array<int, 2> ans = {a[0], 1}; 
    for (int i = 1; i < n; i++) {
        if (a[i] > ans[0]) {
            ans[0] = a[i];
            ans[1] = i + 1;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i++)
        cin >> a[i];
    array<int, 2> ans = max_func(a, n);
    printf("Max is %d, number %d in the array.\n", ans[0], ans[1]);
    system("pause");
    return 0;
}