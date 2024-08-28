#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

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
                    st.insert()
                }
            }
        }
    }

    vector<vector <int>> ans (st.begin(), st.end());
    return ans;
}


int main()
{
    return 0;
}