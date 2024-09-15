#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string conver_binary(int n)
{
    string result = "";

    while (n != 1)
    {
        cout << n << endl;
        if (n % 2 == 1)
            result += "1";
        else
            result += "0";
        n = n / 2;
    }
    result += "1";
    reverse(result.begin(), result.end());
    return result;
}

int binary_decimal(string str)
{
    int len = str.length();
    int num = 0;
    int pow2 = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == '1')
        {
            num = num + pow2;
        }
        pow2 *= 2;
    }

    return num;
}

int main()
{
    int n;
    cout << "Enter the number covert to binary : ";
    cin >> n;
    string res = conver_binary(n);
    cout << "Binary equivalent : " << res << endl;

    string str;
    cout << "Enter Binary : ";
    cin >> str;
    int ans = binary_decimal(str);
    cout << "Binary to decimal : " << ans << endl;

    int val = 13 | 7;
    cout << val << endl;

    return 0;
}