#include <iostream>
using namespace std;


class heap{
    public:
        int arr[100];
        int size;

    heap(){
        size = 0;
        arr[0] = -1;
    }

    void insert(int data ){
        size++;
        int index = size;
        arr[index] = data;

        while (index > 1){
            int parent = index/2;
            
            if ( arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }

        }
    }

    void deleteformheap(){

        if ( size == 0 ){
            cout << "Heap is already empty : " << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int index = 1;
        while(index < size){
            int indexleft = 2*index;
            int indexright = 2*index+1;

            if (indexleft < size && arr[indexleft] > arr[index] && arr[indexleft] > arr[indexright]){
                swap(arr[index] , arr[indexleft]);
                index = indexleft;
            }
            else if (indexright < size && arr[indexright] > arr[index]&& arr[indexleft] < arr[indexright] ){
                swap(arr[index] , arr[indexright]);
                index = indexright;
            }
            else {
                return;
            }
        }
    }



    void print(){
        for (int i=1 ; i<=size ; i++){
            cout << " " << arr[i];
        }
        cout << endl;
    }
};


void heapify(int *arr , int size , int index ){

    int largest = index;
    int leftindex = 2*index;
    int rightindex = 2*index +1;

    if (index < size && arr[largest] < arr[leftindex]){
        largest = leftindex;
    }

    if (index < size && arr[largest] < arr[rightindex]){
        largest = rightindex;
    }

    if (largest != index ){
        swap(arr[index] , arr[largest]);
        cout << "swap"<< endl;
        heapify(arr , size , largest);
    }
    
}


int main(){

    heap h;

    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(55);
    h.insert(75);

    h.print();

    h.deleteformheap();

    h.print();

    int arr[6] = {-1 , 10 , 55 , 53 , 52 ,  50};
    for ( int i=1 ; i<=5 ; i++){
        cout << " " << arr[i];
    }
    cout << endl;
    int size = 5;
    for ( int i=size/2 ; i>1 ; i-- ){
    heapify(arr , size , i);
    }


    for ( int i=1 ; i<=5 ; i++){
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}