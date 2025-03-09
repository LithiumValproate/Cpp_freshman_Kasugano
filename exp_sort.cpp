#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

vector<int> counting_sort(const vector<int>& vec) {
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

vector<int> selection_sort(const vector<int>& vec) {
    vector<int> output = vec;
    for (int i = 0; i < output.size() - 1; i++) {
        int tmp = i;
        for (int j = i + 1; j < output.size(); j++) {
            if (output[j] < output[tmp])
                tmp = j;
        }
        swap(output[i], output[tmp]);
    }
    return output;
}

vector<int> bubble_sort(const vector<int>& vec) {
    vector<int> output = vec;
    for (int i = 0; i < output.size() - 1; i++)
        for (int j = 0; j < output.size() - i - 1; j++)
            if (output[j] > output[j + 1]) {
                int tmp = output[j];
                output[j] = output[j + 1];
                output[j + 1] = tmp;
            }
    return output;
}

int main() {
    cout << "Please enter numbers to sort:\n"
         << "Please ends in any character not belongs to numbers\n";
    int tmpIn;
    vector<int> vecIn;
    while (cin >> tmpIn)
        vecIn.push_back(tmpIn);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please switch which sort you want to use:\n"
         << "1. Counting Sort\n"
         << "2. Selection Sort\n"
         << "3. Bubble Sort\n";
    int s;
    cin >> s;
    vector<int> ans;
    switch (s) {
    case 1:
        ans = counting_sort(vecIn);
        break;
    case 2:
        ans = selection_sort(vecIn);
        break;
    case 3:
        ans = bubble_sort(vecIn);
        break;
    default:
        cout << "Invalid option. Using Bubble Sort by default.\n";
        ans = bubble_sort(vecIn);
        break;
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}