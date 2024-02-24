#include <iostream>
#include <stack>
using namespace std;



void DeleteMiddleElement ( stack <int>& arr, int count , int size ){
    if ( count == size / 2 ){
        arr.pop();
        return;
    }

    int num = arr.top();
    arr.pop();
    DeleteMiddleElement(arr , count+1 , size);
    arr.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
    DeleteMiddleElement(inputStack , 0 , N);

}

int main()
{
    
    return 0;
}