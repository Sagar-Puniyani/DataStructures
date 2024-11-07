#include <iostream>
#include <vector>
using namespace std;

int largestCombination(vector<int> &candidates)
{
    int ans = 0;

    for (int i = 0; i <= 31; i++)
    {
        int cnt = 0;
        for (auto  candidate : candidates)
        {
            if (candidate & (1 << i)){
                cnt ++;
            }
        }

        ans = max(ans, cnt);
    }

    return ans;
}

int main()
{
    vector<int> candidates = {8,8};
    int ans = largestCombination(candidates);
    cout << "ans : " << ans << endl;
    return 0;
}