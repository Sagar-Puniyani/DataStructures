#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (vector<int> arr : matrix)
    {
        for (int item : arr)
        {
            cout << item << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> triplet(int n, vector<int> &arr)
{

    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> tripletBetter(int n, vector<int> &arr)
{

    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int remaining = -(arr[i] + arr[j]);

            if (hashset.find(remaining) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], remaining};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> tripletOPT(int n, vector<int> &arr)
{
    vector <vector <int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && arr[i] == arr[i-1]) continue;

        int j = i + 1, k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i] , arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                

                while (j<k && arr[j-1] == arr[j]) j++;
            }
        }
    }

    return ans;
}

// int main()
// {
//     vector<int> arr = {-2,0,1,1,2};
//     vector<vector<int>> ans = tripletOPT(arr.size(), arr);
//     printMatrix(ans);

//     return 0;
// }