#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;
vector<int> counting_sort(vector<int>);
int main() {
    cout << "Please enter numbers to sort:" << endl 
         << "Please ends in any charcter not belongs to numbers" << endl;
    int tmpIn;
    vector<int> vecIn;
    while(cin >> tmpIn)
        vecIn.push_back(tmpIn);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int s;
    vector<int> ans(vecIn.size());
    cout << "Please switch which sort you want to use:" << endl
         <<"1. Counting Sort." << endl;
    cin >> s;
    switch(s) {
        case 1:
            ans = counting_sort(vecIn);
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            break;
        default:
            break;
    
    }
}
vector<int> counting_sort(vector<int>& vec) {
    int minVal = *min_element(vec.begin(), vec.end());
    int maxVal = *max_element(vec.begin(), vec.end());
    int range = maxVal - minVal + 1;
    int count[range] = {0};
    for (int i = 0; i < vec.size(); i++)
        count[vec[i] - minVal]++;
    vector<int> output(vec.size());
    for (int i = range - 1; i >= 0; i--)
        for (int j = 0; j < count[i]; j++)
            output.push_back(i + minVal);
    reverse(output.begin(), output.end());
    return output;
}