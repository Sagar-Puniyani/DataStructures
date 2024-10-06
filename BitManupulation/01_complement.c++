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

void swapping(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
// bit set or not
bool checkKthBit(int n, int k)
{
    // Your code here
    // It can be a one liner logic!! Think of it!!
    //! It is the left shift
    return n & (1 << k);
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

    val = 13 >> 1;
    cout << "Right shift : " << val << endl;

    val = 13 << 1;
    cout << "Left shift : " << val << endl;

    val = ~5;
    cout << "Not operator : " << val << endl;

    int a = 10, b = 20;
    swapping(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "0 shift : " << 1<<0 << endl;

    cout << "Bit set or not : " << checkKthBit(4, 0) << endl;

    return 0;
}