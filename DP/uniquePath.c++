#include <iostream>
#include <vector>
using namespace std;

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

int solve(int m, int n, vector< vector<int>> &dp){

}

int uniquePaths(int m, int n) {
    vector < vector <int>> dp(m, vector<int> (n,-1));
    dp[0][0] = 1;
    return solveTab(m-1,n-1,dp);
}




int main(){

    int m , n;
    cout << "Enter no. of rows : " ;
    cin >> m;

    cout << "Enter no. of  cols : " ;
    cin >> n;

    int ans = uniquePaths(m,n);
    cout << "Ans = " << ans << endl;

    return 0;
}