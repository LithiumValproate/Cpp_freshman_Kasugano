#include <cmath>
#include <iostream>
using namespace std;
int f(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += i;
    return ans;
}
int w(int n) {
    int i = 1, ans = 0;
    while (i <= n) {
        ans += i;
        i++;
    }
    return ans;
}
int d(int n) {
    int i = 1, ans = 0;
    do {
        ans += i;
        i++;
    } while (i <= n);
    return ans;
}
void fp(int n) {
    for (int i = 1; i <= n; i++) {
        if (i <= 2)
            cout << i << ' ';
        else
            for (int j = 2; j <= ceil(sqrt(i)); j++) {
                if (i % j == 0)
                    break;
                if (j == ceil(sqrt(i)))
                    cout << i << ' ';
            }
    }
    cout << endl;
}
int main() {
    cout << "Input the N you want to sum in a loop:\n";
    int n, c, sum = 0;
    cin >> n;
    cout << "Enter 1 to sum via \033[3mfor\033[0m\n"
         << "Enter 2 to sum via \033[3mwhile\033[0m\n"
         << "Enter 3 to sum via \033[3mdo-while\033[0m\n";
    cin >> c;
    switch (c) {
    case 1:
        sum = f(n);
    case 2:
        sum = w(n);
    case 3:
        sum = d(n);
    default:
        cout << "The sum is: " << sum << endl;
        break;
    }
    cout << "Here are primes within N:\n";
    fp(n);
    system("pause");
    return 0;
}