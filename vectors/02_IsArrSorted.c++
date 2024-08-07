#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int count = 0;
    
    int n = nums.size();

    for ( int i=0; i<nums.size(); i++){
        if(nums[i] > nums[(i+1) % n]){
            count ++;
        }
    }

    return count <= 1;
}

int main()
{
    vector <int> nums = {4,5,1,2,3};
    bool ans = check(nums);
    cout << "Is Sorted : " << ans << endl;
    return 0;
}