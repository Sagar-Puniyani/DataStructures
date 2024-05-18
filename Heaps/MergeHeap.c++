#include <iostream>
#include <vector>
using namespace std;

void heapify(vector <int>& arr , int size , int index){
    int largest = index;
    int leftindex = 2*index+1;
    int rightindex = 2*index +2;

    if (leftindex<size && arr[largest] < arr[leftindex]){
        largest = leftindex;
    }

    if (rightindex < size && arr[largest] < arr[rightindex]){
        largest = rightindex;
    }

    if (largest != index ){
        swap(arr[index] , arr[largest]);
        cout << "swap"<< endl;
        heapify(arr , size , largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> c = a;

    for ( auto i : b )
        c.push_back(i);

    int size = c.size();
    cout << "c.size  = "<< size << endl;
    for (auto i : c ){
        cout << " " << i;
    }
    for ( int i=size/2 -1; i>=0 ; i--){
        heapify(c,size,i);
    }

    return c;

}

int main()
{
    vector <int> a = {10, 5, 6, 2};
    vector <int> b = {12, 7, 9};

    vector <int> c = mergeHeaps(a , b , 4 , 3);
    for (auto i : c ){
        cout << " " << i;
    }
    cout << endl;
    return 0;
}