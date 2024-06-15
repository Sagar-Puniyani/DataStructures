#include <iostream>
#include <vector>
#include <map>
using namespace std;

void pushinAns(vector <vector <int>> &ans, vector <vector <int>> &board){
    vector <int> res;

    for ( vector<int> row : board){
        for ( int col : row ){
            res.push_back(col);
        }
    }
    ans.push_back(res);
}


bool isSafe(int row, int col, vector <vector <int>> board, int n ){
    // row 
    for ( int y=0; y<col; y++){
        if ( board[row][y] == 1){
            return false;
        }
    }

    // Daigonal (up)
    int x = row;
    int y = col;

    while( x>=0 && y>=0){
        if (board[x][y] == 1 ){
            return false;
        }
        x--;
        y--;
    }

    // Daigonal (down)
    x = row;
    y = col;

    while( x<n && y>=0){
        if (board[x][y] == 1 ){
            return false;
        }
        x++;
        y--;
    }

    return true;
}


bool isSafeFast(int row, int col, vector <vector <int>> board, int n, map <int , bool > &mapRow, 
            map <int , bool> &mapDaigonalDown,map <int , bool> &mapDaigonalUp
){

    if (mapRow[row] == true || 
        mapDaigonalDown[row+col] == true ||
        mapDaigonalUp[n-1+ col-row] == true)
    {
        return false;
    }

    return true;
}

void solve(int col, vector <vector <int>> &ans, vector <vector <int>> &board, int n,map <int , bool > &mapRow, 
            map <int , bool> &mapDaigonalDown,map <int , bool> &mapDaigonalUp){
    // base case ( all cols are filled)
    if ( col == n ){
        pushinAns(ans , board);
        return;
    }

    

    for ( int row=0 ; row<n; row++){
        if ( isSafeFast(row , col , board, n,mapRow,mapDaigonalDown, mapDaigonalUp)){
            board[row][col] = 1;

            // entry in map
            mapRow[row] = true;
            mapDaigonalDown[row+col] = true;
            mapDaigonalUp[n-1 + col-row] = true;

            solve(col+1,ans,board,n, mapRow, mapDaigonalDown, mapDaigonalUp);

            // backtracking
            mapRow[row] = false;
            mapDaigonalDown[row+col] = false;
            mapDaigonalUp[n-1 + col-row] = false;
            board[row][col] = 0;
        }
    }

}

vector<vector<int>> nQueens(int n)
{
    vector <vector <int>> board(n , vector<int>(n,0));
    vector <vector <int>> ans;

    map <int , bool > mapRow;
    map <int , bool > mapDiagonalDown;
    map <int , bool > mapDiagonalUp;

    solve(0,ans,board,n, mapRow, mapDiagonalDown, mapDiagonalUp);
    return ans;

}


int main(){

    vector<vector<int>> ans = nQueens(5);
    cout <<"N Queen : " <<endl;
    for ( auto item : ans ){
        for ( auto element : item) {
            cout << " " << element;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}