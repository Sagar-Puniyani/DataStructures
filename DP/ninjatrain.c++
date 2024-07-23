#include <iostream>
#include <vector>
using namespace std;

void printArr(vector <vector <int>> arrarys ){
    for (const auto &array : arrarys){
        for (const auto &element : array){
            cout<< element << "  ";
        }
        cout << endl;
    }
    cout << endl;
}


int solve(int day, int last, vector<vector <int>> &points, vector<vector <int>> &dp ){

    int maxi = 0;
    if ( day == 0 ){
        for (int i=0; i<=2; i++){
            if (i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }

    if ( dp[day][last] != -1 ) return dp[day][last];


    maxi = 0;

    for (int i=0; i<=2; i++){
        if ( i != last){
            int score = points[day][i] + solve(day-1, i, points, dp);
            maxi = max(maxi, score);
        }
    }
    return dp[day][last] = maxi;
}

int maximumPoints(vector<vector<int>>& points, int n) {
    vector<vector <int>> dp(n,vector <int>(4,-1));
    printArr(dp);
    int ans = solve(n-1, 3, points, dp);
    printArr(dp);
    return ans;
}

int main(){
    vector<vector <int>> points = { {2,1,3},
                                    {3,4,6},
                                    {10,1,6},
                                    {8,3,7}};

    int n = points.size();
    cout << "n = " << n << endl;

    cout << "maximum point" << endl;
    int ans = maximumPoints(points, n);
    cout << "Ans : " << ans << endl;

    printArr(points);
    return 0;
}