#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{

    int maxi = 0;
    int count = 0;

    for (int item : nums)
    {
        if (item == 1)
        {
            count++;
            maxi = max(maxi, count);
        }
        else
        {
            count = 0;
        }
    }

    return maxi;
}

// the number which is not appering twice
// xor of whole array
int singleNumber(vector<int> &nums)
{
    int x=0;
    for ( int item : nums ){
        x = x ^ item;
    }
    return x;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    int ans = findMaxConsecutiveOnes(arr);
    cout << "Ans : " << ans << endl;

    vector<int> nums = {4,3,5,1,1,4,3};
    int XorAns = singleNumber(nums);
    cout << "single number  : " << XorAns << endl;


    return 0;
}