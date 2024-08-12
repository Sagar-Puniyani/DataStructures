#include <iostream>
#include <set>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    for (int item : arr)
    {
        cout << item << "  ";
    }
    cout << endl;
}

vector<int> findUnionSet(vector<int> arr1, vector<int> arr2)
{
    set<int> st;
    for (int item : arr1)
        st.insert(item);
    for (int item : arr2)
        st.insert(item);

    vector<int> ans;
    for (int item : st)
        ans.push_back(item);

    return ans;
}

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;  // pointers
    vector<int> Union; // Uninon vector
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}


int main()
{
    vector<int> arr1 = {1, 2, 2, 2, 3, 4, 5, 5, 5, 5, 5};
    vector<int> arr2 = {0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};

    vector<int> ans = findUnionSet(arr1, arr2);
    printArr(ans);

    int n = 10, m = 7;
    int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr4[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr3, arr4, n, m);
    cout << "Union of arr3 and arr4 is  " << endl;
    for (auto &val : Union)
        cout << val << " ";

    return 0;
}