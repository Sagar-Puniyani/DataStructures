#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printArr(vector<int> arr)
{
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
}

// hash solution
vector<int> majorityElement(vector<int> v)
{
    int n = v.size();
    vector<int> ans;

    unordered_map<int, int> m;
    int mini = int(n / 3) + 1;

    for (int i = 0; i < n; i++)
    {
        m[v[i]]++;

        if (m[v[i]] == mini)
        {
            ans.push_back(v[i]);
        }

        if (ans.size() == 2)
            break;
    }

    return ans;
}

// extended Moore’s Voting Algorithm
vector<int> mooreAlgo(vector <int> arr){
    int n = arr.size();
    int element1 = 0;
    int element2 = 0;

    int count1 = 0;
    int count2 = 0;

    for ( int i=0; i<n ; i++){
        if ( count1 == 0 && element2 != arr[i]){
            count1 = 1;
            element1 = arr[i];
        }
        else if (count2 == 0 && element1 != arr[i]){
            count2 = 1;
            element2 = arr[i];
        }
        else if (element1 == arr[i]) count1 ++;
        else if (element2 == arr[i]) count2 ++;

        else{
            count1--;
            count2--;
        }
    }

    vector <int> ans;
    
    count1 = 0, count2 = 0;

    for ( int i=0; i<n; i++){
        if (arr[i] == element1) count1++;
        if (arr[i] == element2) count2++;
    }

    int mini = (int) (n/3) + 1;
    if (count1 >= mini ) ans.push_back(element1);
    if (count2 >= mini ) ans.push_back(element2);

    return ans;

}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    printArr(ans);

    vector<int> ans1 = mooreAlgo(arr);
    cout << "The majority elements are: ";
    printArr(ans1);

    return 0;
}