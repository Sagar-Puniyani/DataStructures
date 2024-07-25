#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr){
    for (auto element : arr ){
        cout << element << " ";
    }
    cout << endl;
}

int solveMemo(int i, int j, vector< vector<int>> &dp){
    if( i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;

    if( dp[i][j] != -1 ) return dp[i][j];

    // coming from direction
    int up = solveMemo(i-1,j,dp);
    int left = solveMemo(i,j-1,dp);

    return dp[i][j] =  up+left;
}

int solveTab(int m, int n,vector< vector <int>> &dp){
    for ( int i=0; i<=m; i++ ){
        for( int j=0; j<=n; j++){

            if (i==0 && j==0) continue;

            int up=0, left=0;

            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[m][n];
}

int uniquePaths(int m, int n) {
    vector < vector <int>> dp(m, vector<int> (n,-1));
    dp[0][0] = 1;
    return solveTab(m-1,n-1,dp);
}

int solve(int m, int n, vector<int> &dp){
    cout <<"dp" << endl;
    printArr(dp);
    for ( int i=0; i<=m; i++ ){
        vector <int> temp(n+1,0);
        temp[0] = 1;
        for( int j=1; j<=n; j++){

            int up=0, left=0;

            if(i>0) up = dp[j];
            if(j>0) left = temp[j-1];

            temp[j] = up + left;
        }
        dp = temp;
        printArr(temp);
    }

    return dp[n];
}

int uniquePathsSpaceOPT(int m, int n) {
    vector <int> dp(n,1);
    return solve(m-1,n-1,dp);
}


int uniquePathsWithObstacles(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();

    vector <int> dp(n,1);

    for ( int i=0; i<m; i++ ){
        vector <int> temp(n,0);
        for( int j=0; j<n; j++){
            if (arr[i][j] == 1 ) {
                temp[j] = 0;
                continue;
            }

            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }

            int up=0, left=0;

            if(i>0) up = dp[j];
            if(j>0) left = temp[j-1];

            temp[j] = up + left;
        }
        dp = temp;
        printArr(dp);
    }

    return dp[n-1];
}




int main(){

    // int m , n;
    // cout << "Enter no. of rows : " ;
    // cin >> m;

    // cout << "Enter no. of  cols : " ;
    // cin >> n;

    // int ans = uniquePathsSpaceOPT(m,n);
    // cout << "Ans = " << ans << endl;

    vector < vector <int>> obstacleGrid = {{0}};

    cout << "Ans of Maze block : " << uniquePathsWithObstacles(obstacleGrid)<< endl;

    return 0;
}