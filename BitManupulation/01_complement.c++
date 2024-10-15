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

int setKthBit(int n, int k){
    n = n | (1<<k);
    return n;
}

int clearKthBit(int n, int k){
    n = n & ~(1<<k);
    return n;
}

int ToggleKthBit(int n, int k){
    n = n ^ (1<<k);
    return n;
}

// toggle the Last set bit
int toggleLastSetBit(int n){
    return n&(n-1);
}

bool checkPowerOf2(int n){
    if (n & (n-1) == 0){
        return true;
    }
    return false;
}

int countSetBits(int n ){
    int cnt = 0;
    while (n > 1)
    {
        cnt += (n & 1);
        n = n >> 1;        
    }
    if (n == 1) cnt++;

    return cnt;
    
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

    cout << "10 ^ 0 : " << (int)(a ^ 0) << endl;

    int num = 9;
    cout << "set bit : "<< setKthBit(num,2) << endl;

    cout << "Toggle ith Bit : " << ToggleKthBit(num, 2) << endl;
    num = 13;
    cout << "Clear ith Bit : " << clearKthBit(num, 2)<< endl;

    cout << "Toggle Last set bit : " << toggleLastSetBit(84) << endl;

    cout << "Check power of 2 : " << (int)(checkPowerOf2(8)) << endl;


    return 0;
}