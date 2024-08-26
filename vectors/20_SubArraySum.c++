#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int cnt = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += arr[j];

            if (sum == k)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int subarraySum(vector<int> &nums, int k)
{
    int preSum  = 0, cnt = 0;
    map<int, int> m;
    int n = nums.size();
    m[0] = 1;

    for ( int i=0; i<n; i++){

        preSum += nums[i];

        int remain = preSum - k;

        cnt += m[remain];

        m[preSum] += 1;
    }

    return cnt;

}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int ans = findAllSubarraysWithGivenSum(arr, 6);
    cout << "sub array with sum  k : " << ans << endl;

    int res = subarraySum(arr, 6);

    cout << "sub array with sum  k : " << res << endl;

    return 0;
}