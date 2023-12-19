#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <float> items = {10,20,30,40,50};
    items.push_back(90);
    items.push_back(45);
    items.push_back(62);
    items.pop_back();

    for (size_t i = 0 ; i < items.size() ; i++){
        cout << "items[" << i << "] = " << items.at(i) << endl; 
    }
    return 0;
}