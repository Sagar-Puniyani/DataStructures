#include <iostream>
using namespace std;

struct  PetrolPump {
    int petrol;
    int distance;
};

int tour(PetrolPump p[],int n){

    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i =0 ; i<n ; i++ ) {
        balance += p[i].petrol - p[i].distance;
        if ( balance < 0 ){
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    if ( deficit + balance >= 0 ){
        return start;
    }
    else {
        return -1;
    }
}


int main()
{
    int n = 4;
    PetrolPump p[n];
    p[0].petrol  = 4;
    p[0].distance = 6;

    p[1].petrol  = 6;
    p[1].distance = 5;

    p[2].petrol  = 7;
    p[2].distance = 3;

    p[3].petrol  = 4;
    p[3].distance = 5;

    int ans = tour(p , n );
    cout << "ans : " << ans << endl;

    int num = 6;

    PetrolPump pp[num];

    pp[0].petrol = 6;
    pp[0].distance = 5;
    
    pp[1].petrol = 7;
    pp[1].distance = 6;

    pp[2].petrol = 4;
    pp[2].distance = 7;

    pp[3].petrol = 10;
    pp[3].distance = 8;

    pp[4].petrol = 6;
    pp[4].distance = 6;

    pp[5].petrol = 5;
    pp[5].distance = 4;

    int answer = tour(pp , num );
    cout << "Answer = " << answer << endl;


    return 0;
}