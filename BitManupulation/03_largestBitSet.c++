#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int largestCombination(vector<int> &candidates)
{
    int ans = 0;

    for (int i = 0; i <= 31; i++)
    {
        int cnt = 0;
        for (auto candidate : candidates)
        {
            if (candidate & (1 << i))
            {
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    return ans;
}

// right most Unset Bit
int RightmostUnsetBit(int n)
{
    return ~n & (n + 1);
}

// set the Rightmost Unset Bit
int SetRightUnsetBit(int n)
{
    int rightUnset = log2(~n & (n + 1));

    return  n | (1 << rightUnset);
}

int main()
{
    vector<int> candidates = {8, 8};
    int ans = largestCombination(candidates);
    cout << "ans : " << ans << endl;

    cout << "Right most Unset Bit : " << log2(RightmostUnsetBit(15)) << endl;

    cout << "Set the Last Unset Bit : " << SetRightUnsetBit(16) << endl;

    return 0;
}