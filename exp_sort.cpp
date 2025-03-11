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
            if (output[j] > output[j + 1])
                swap(output[j], output[j + 1]);
    return output;
}

vector<int> insertion_sort(const vector<int>& vec) {
    vector<int> output = vec;
    for (int i = 1; i < output.size(); i++) {
        int key = output[i];
        int j = i - 1;
        while (j >= 0 && output[j] > key) {
            output[j + 1] = output[j];
            j--;
        }
        output[j + 1] = key;
    }
    return output;
}

vector<int> quick_sort(vector<int> vec, int l, int r) {
    if (l < r) {
        int pivot = l + (r - l) / 2;
        int i = l, j = r;
        while (i <= j) {
            while (vec[i] < vec[pivot])
                i++;
            while (vec[j] > vec[pivot])
                j--;
            if (i <= j) {
                swap(vec[i], vec[j]);
                i++;
                j--;
            }
        }
        if (l < j)
            vec = quick_sort(vec, l, j);
        if (i < r)
            vec = quick_sort(vec, i, r);
    }
    return vec;
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
         << "3. Bubble Sort\n"
         << "4. Insertion Sort\n"
         << "5. Quick Sort\n";
    int s;
    cin >> s;
    vector<int> ans;
    int l = 0, r = vecIn.size() - 1;
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
    case 4:
        ans = insertion_sort(vecIn);
        break;
    case 5:
        ans = quick_sort(vecIn, l, r);
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