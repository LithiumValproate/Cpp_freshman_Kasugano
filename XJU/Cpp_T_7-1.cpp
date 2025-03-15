#include <iostream>
#include <string>
using namespace std;
class Clock{
    public:
    string h, m, s;
    string time(string h, string m, string s) {
        string output = h + ":" + m + ":" + s;
        return output;
    }
};
int main() {
    Clock input;
    cin >> input.h >> input.m >> input.s;
    cout << input.time(input.h, input.m, input.s);
    return 0;
}