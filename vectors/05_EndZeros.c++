#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

// brute approach
void moveZeroesBrute(vector<int> &nums)
{
    int count = 0;

    for (int item : nums)
    {
        if (item == 0)
            count++;
    }

    vector<int> arr;
    for (int item : nums)
    {
        if (item != 0)
            arr.push_back(item);
        if (item == 0)
            continue;
    }

    while (count--)
    {
        arr.push_back(0);
    }

    nums = arr;
}

// optimized approach
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int j = -1;
    for (int i=0; i<n; i++){
        if ( nums[i] == 0 ){
            j = i;
            break;
        }
    }

    if ( j == -1 ) return;

    for (int i=j+1; i<n; i++ ){
        if (nums[i] != 0){
            swap(nums[i], nums[j++]);
        }
    }
}

//

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    printArr(nums);
    moveZeroes(nums);
    printArr(nums);

    return 0;
}