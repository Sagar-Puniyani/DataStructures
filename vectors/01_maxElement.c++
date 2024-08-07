#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    cout << "Print of Array " << endl;
    for (auto item : arr)
    {
        cout << item << "  ";
    }
    cout << endl;
}

// largest element in the Array

int largestElement(vector<int> &arr, int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i]);
    }
    return ans;
}

// second largest and smallest element in the array

vector<int> getSecondOrderElements(int n, vector<int> arr)
{
    vector<int> ans;

    // largest and smallest
    int l_first = INT_MIN;
    int l_second = INT_MIN;
    int s_first = INT_MAX;
    int s_second = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > l_first)
        {
            l_second = l_first;
            l_first = arr[i];
        }

        else if ( arr[i] > l_second && arr[i] != l_first ){
            l_second = arr[i];
        }


        if (arr[i] < s_first)
        {
            s_second = s_first;
            s_first = arr[i];
        }
        else if (arr[i] < s_second && arr[i] != s_first)
        {
            s_second = arr[i];
        }
    }

    ans.push_back(l_second);
    ans.push_back(s_second);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int ans = largestElement(arr, arr.size());
    cout << "value of largest element is : " << ans << endl;

    vector<int> arrAns = getSecondOrderElements(arr.size(), arr);
    printArr(arrAns);
    return 0;
}