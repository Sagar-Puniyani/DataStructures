#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
}

// Max Profit of Stock Buy and Sell
int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int n = prices.size();
    int ans = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        mini = min(mini, prices[i]);
        ans = max(ans, prices[i] - mini);
    }

    return ans;
}

// Rearranging Array
void RearrangebySign(vector<int> &prices)
{
    vector<int> pos;
    vector<int> neg;

    for (int price : prices)
    {
        if (price > 0)
            pos.push_back(price);
        else
            neg.push_back(price);
    }

    int n = prices.size();
    prices.clear();

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            prices.push_back(pos[x++]);
        else
            prices.push_back(neg[y++]);
    }
}

void RearrangebySignOPT(vector<int> &prices)
{
    int n = prices.size();
    vector<int> arr(n, 0);
    int pos = 0, neg = 1;

    for (int i=0; i < n; i++)
    {
        if ( prices[i] > 0 ) {
            arr[pos] = prices[i];
            pos += 2;
        }
        else{
            arr[neg] = prices[i];
            neg += 2;
        }
    }
}

int main()
{
    vector<int> arr = {7, 6, 4, 3, 1};
    int ans = maxProfit(arr);
    cout << "Max Profit : " << ans << endl;

    vector<int> array = {1, 2, -4, -5};
    RearrangebySign(array);
    printArr(array);

    RearrangebySignOPT(array);
    printArr(array);


    return 0;
}