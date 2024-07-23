#include <iostream>
#include <vector>
#include <algorithm>
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



// memorization
int solveMemo(int day, int last, vector<vector <int>> &points, vector<vector <int>> &dp ){

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
            int score = points[day][i] + solveMemo(day-1, i, points, dp);
            maxi = max(maxi, score);
        }
    }
    return dp[day][last] = maxi;
}



int maximumPoints(vector<vector<int>>& points, int n) {
    vector<vector <int>> dp(n,vector <int>(4,-1));
    printArr(dp);
    int ans = solveMemo(n-1, 3, points, dp);
    printArr(dp);
    return ans;
}

// Tabulation
int maximumPointsTab(vector<vector<int>>& points, int n) {
    vector<vector <int>> dp(n,vector <int>(4,0));

    // Base case for day 0
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for ( int day=1; day< n; day++){
        for (int last=0; last<=3; last++){

            dp[day][last] = 0;
            for ( int task =0; task <=2; task++){
                if ( task != last){
                    int score = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(score , dp[day][last]);
                }
            }
        }
    }

    int ans = dp[n-1][3];
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

    cout << "Answer : " << maximumPointsTab(points, n) << endl;

    printArr(points);
    return 0;
}