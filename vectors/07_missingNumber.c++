#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int i;
    for (i = 0; i < n; i++)
    {
        bool flag = false;
        for (int item : nums)
        {
            if (i == item)
                flag = true;
        }
        if (!flag)
            break;
    }

    return i;
}

int missingNumberHash(vector<int> &nums)
{

    vector<int> hash(nums.size() + 1, 0);

    for (int item : nums)
    {
        hash[item] = 1;
    }

    int i;
    for (i = 0; i <= nums.size(); i++)
    {
        if (hash[i] == 0)
            break;
    }

    return i;
}

int missingNumberXor(vector<int> &nums)
{
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        xor1 = xor1 ^ (i+1);
        xor2 = xor2 ^ nums[i];
    }
    return xor1 ^ xor2;
}

int main()
{
    vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int ans = missingNumber(arr);
    cout << "Ans = " << ans << endl;

    int missingNum = missingNumberHash(arr);
    cout << "Ans = " << missingNum << endl;


    int xorAns = missingNumberHash(arr);
    cout << "Ans = " << xorAns << endl;
    return 0;
}