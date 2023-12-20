#include <iostream>
#include "vector.hpp"
using namespace std;


int main()
{
    vector <float> v ;
    v.push_back(10.0f);
    v.push_back(20.13f);
    v.push_back(30.145f);
    v.push_back(30.145f);
    v.push_back(30.145f);
    v.push_back(30.145f);
    v.push_back(30.145f);
    v.push_back(20.145f);
    v.push_back(30.145f);
    v.push_back(30.145f);

    cout << "size = " << v.size() << endl;
    for(int i=0 ; i < v.size() ; i++){
        cout << "v[" << i << "] = " << v[i] << endl;
    }
    v.Erase(0);
    v.pop_back();
    
    for(int i=0 ; i < v.size() ; i++){
        cout << "v[" << i << "] = " << v[i] << endl;
    }

    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;

    cout << endl ;
    cout << endl ;
    cout << endl ;
    cout << "Assignment" << endl;
    vector <float> w;
    w = v;
    for(int i=0 ; i < w.size() ; i++){
        cout << "w[" << i << "] = " << w[i] << endl;
    }
    return 0;
}