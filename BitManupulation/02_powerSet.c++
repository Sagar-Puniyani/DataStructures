#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector< vector<int> > powerSet(vector<int> arr){

    int n = arr.size();
    vector< vector<int> > res(1<<n);

   for ( int num = 0 ; num < (1<<n) ; num++ ){
        for ( int i = 0 ; i < n ; i++ ){
            if (num & (1<<i)){
                res[num].push_back(arr[i]);
            }
        }
    }

    return res;

}

// single Number(map)
int singleNumberMAP(vector<int>& nums) {
    map <int , int > mp;   
    for ( int i = 0 ; i < nums.size() ; i++ ){
        mp[nums[i]]++;
    }
    for ( auto [key , value] : mp ){
        if (value == 1){
            return key;
        }
    }

    return -1;
}

// single Number(xor)
int singleNumberXOR(vector<int>& nums) {
    int ans = 0;
    for (int num : nums ){
        ans = ans ^ num;
    }
    return ans;
}

// single Number II 


int main(){
    vector <int> arr = {1, 2, 3};

    vector< vector<int> > res = powerSet(arr);

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    vector <int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number : "  << singleNumberMAP(nums) << endl;
    cout << "Single Number : "  << singleNumberXOR(nums) << endl;


    return 0;
}