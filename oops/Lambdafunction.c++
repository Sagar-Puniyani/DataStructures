#include <iostream>
#include <vector>
#include <functional>
using namespace std;


void ForEach( const vector <int> values , const function<void(int)> &func){
    for ( int value : values ){
        func(value);
    }
} 

int main(){
    vector <int> values = {10 , 20 , 30 , 40 , 50};

    int increment = 3;

    auto lambda = [&increment](int value) { cout <<"value : " << value + increment << endl;};
    ForEach( values , lambda);

    return 0;
}