#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto item : arr)
    {
        cout << item << "  ";
    }
    cout << endl;
}

void rotate(vector<int> &nums, int k)
{
    vector<int> arr(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        arr[i] = nums[(i + k) % nums.size()];
    }
    nums = arr;
}

vector<int> rotateArray(vector<int> &arr, int k)
{
    k = k % arr.size();
    int n = arr.size();

    vector<int> temp(k);

    // copy to temp
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    cout << "Temp array " << endl;
    printArr(temp);

    // shift arr
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    cout << "shited array " << endl;
    printArr(arr);

    // place the temp arr
    for (int i = 0; i < k; i++)
    {
        arr[(n - k) + i] = temp[i];
    }

    printArr(arr);

    return arr;
}

void reverseArr(vector<int>&arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start++] , arr[end--]);
    }
}

vector<int> RotateReverse(vector<int> &arr, int k)
{
    int n = arr.size();

    reverseArr(arr,0,n-k-1);
    reverseArr(arr,n-k,n-1);
    reverseArr(arr,0,n-1);

    return arr;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    printArr(nums);

    vector<int> ans = RotateReverse(nums, 3);
    printArr(ans);

    return 0;
}