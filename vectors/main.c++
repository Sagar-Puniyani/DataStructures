#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <float> items = {10,20,30,40,50};
    items.push_back(90.0f);
    items.push_back(45.0f);
    items.push_back(62.0f);
    items.pop_back();

    for (size_t i = 0 ; i < items.size() ; i++){
        cout << "items[" << i << "] = " << items.at(i) << endl; 
    }

    size_t index = 0;
    for (const auto& item : items) {
        cout << "items[" << index << "] = " << item << endl;
        ++index;
    }
    return 0;
}