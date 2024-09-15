#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &arr)
{
    int n = arr.size();

    int maxLen = 0;
    int sum = 0;

    
    for (int i = 0; i < arr.size(); i++) {
        sum += a[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        } else {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    return 0;
}