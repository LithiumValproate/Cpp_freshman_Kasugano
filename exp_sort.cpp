#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

vector<int> counting_sort(const vector<int>&);

int main() {
    cout << "Please enter numbers to sort:" << endl 
         << "Please ends in any character not belongs to numbers" << endl;
    int tmpIn;
    vector<int> vecIn;
    while(cin >> tmpIn)
        vecIn.push_back(tmpIn);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int s;
    vector<int> ans;
    cout << "Please switch which sort you want to use:" << endl
         << "1. Counting Sort." << endl;
    cin >> s;
    switch(s) {
        case 1:
            ans = counting_sort(vecIn);
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
            break;
        default:
            break;
    }
    system("pause");
    return 0;
}

vector<int> counting_sort(const vector<int>& vec) {
    if (vec.empty())
        return {};
    int minVal = *min_element(vec.begin(), vec.end());
    int maxVal = *max_element(vec.begin(), vec.end());
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);
    for (int x : vec)
        count[x - minVal]++;
    vector<int> output;
    output.reserve(vec.size());
    for (int i = 0; i < range; i++)
        for (int j = 0; j < count[i]; j++)
            output.push_back(i + minVal);
    return output;
}