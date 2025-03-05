#include <iostream>
using namespace std;
int main() {
    int h[10], l;
	for (int i = 0; i < 10; i++)
		cin >> h[i];
	cin >> l;
	int ans = 0;
    l += 30;
	for (int j = 0; j < 10; j++)
		if (h[j] <= l)
			ans += 1;
	cout << ans;
	return 0;
}