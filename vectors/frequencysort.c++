#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void printArr(const vector<int>& arr) {
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first > b.first; // Sort by value in descending order
    }
    return a.second < b.second; // Sort by frequency in ascending order
}

vector<int> frequencySort(vector<int>& nums) {
    map<int, int> freq;
    for (int element : nums) {
        freq[element]++;
    }

    vector<pair<int, int>> freqVec(freq.begin(), freq.end());

    sort(freqVec.begin(), freqVec.end(), compare);

    vector<int> ans;
    for (auto& [key, value] : freqVec) {
        for (int i = 0; i < value; ++i) {
            ans.push_back(key);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3};

    vector<int> ans = frequencySort(nums);
    printArr(ans);
    return 0;
}
