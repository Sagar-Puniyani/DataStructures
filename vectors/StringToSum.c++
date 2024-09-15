#include <iostream>
using namespace std;

int getLucky(string s, int k)
{
    string str = "";
    for (int i = 0; i < s.size(); i++){
        str = str + to_string(s[i] - 'a' + 1);
    }

    cout << "str : " << str << endl;

    int sum = 0;
    while (k--)
    {
        for (int i = 0; i < str.size(); i++)
        {
            sum += str[i] - '0';
        }
        str = to_string(sum);
        sum = 0;
    }
    
    return stoi(str);
}

int main()
{
    int ans = getLucky("zbax", 2);
    cout << "Ans : " << ans << endl;
    return 0;
}