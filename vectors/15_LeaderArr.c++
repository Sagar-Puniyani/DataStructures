#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArr(vector<int> arr)
{
    for (int item : arr)
    {
        cout << item << "  ";
    }
    cout << endl;
}

vector<int> printLeadersBruteForce(int n, vector<int> arr)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }

        if (leader)
            ans.push_back(arr[i]);
    }

    return ans;
}

vector<int> Leader(int n, vector<int> arr)
{
    vector<int> ans;

    int maxi = arr[arr.size() - 1];
    ans.push_back(maxi);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 6;
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeadersBruteForce(n, arr);
    printArr(ans);

    vector<int> res = Leader(n, arr);
    printArr(res);

    return 0;
}