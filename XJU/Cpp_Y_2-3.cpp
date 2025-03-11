#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
long long rec(int i) {
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    else
        return rec(i - 1) + rec(i - 2);
}
long long no_rec(int i) {
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    long long a = 0, b = 1;
    for (int j = 2; j <= i; j++) {
        long long tmp = a + b;
        a = b;
        b = tmp;
    }
    return b;
}
int main() {
    auto startTimeRec = high_resolution_clock::now();
    cout << "Use recursion:\n";
    for (int i = 0; i <= 30; i++) {
        printf("%d: %lld\t", i, rec(i));
        if (i % 5 == 0)
            cout << endl;
    }
    auto endTimeRec = high_resolution_clock::now();
    auto durationRec = duration_cast<microseconds>(endTimeRec - startTimeRec);
    cout << "\nRecursion time used: " << durationRec.count() << " microseconds\n";
    auto startTimeNoRec = high_resolution_clock::now();
    cout << "\nNon-recursion:\n";
    for (int i = 0; i <= 30; i++) {
        printf("%d: %lld\t", i, no_rec(i));
        if (i % 5 == 0)
            cout << endl;
    }
    auto endTimeNoRec = high_resolution_clock::now();
    auto durationNoRec = duration_cast<microseconds>(endTimeNoRec - startTimeNoRec);
    cout << "\nNon-recursion time used: " << durationNoRec.count()
         << " microseconds" << endl;
    system("pause");
    return 0;
}