#include <iostream>
#include "D:\c++\DSA\vectors\vector.hpp"
using namespace std;

int main()
{
    vector <float> v;
    v.push_back(10.0f);
    v.push_back(20.13f);
    v.push_back(30.145f);

    for(int i=0 ; i < v.size() ; i++){
        cout << "v[" << i << "] = " << v[i] << endl;
    }
    return 0;
}