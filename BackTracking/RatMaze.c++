#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int newx ,int newy,  vector < vector < int >> isVisited,  vector < vector < int >>arr, int n ){

    return (newx >= 0 && newx < n && newy >= 0 && newy < n && arr[newx][newy] == 1 && isVisited[newx][newy] == 0);

}

void solve(int x , int y , vector < vector < int >> & arr , vector < vector < int >> & isVisited ,string path , vector < string> &ans , int n){
    // base case
    if ( x == n-1 && y == n-1 ){
        ans.push_back(path);
        return;
    }

    // Down 
    if (isSafe(x+1,y,isVisited, arr, n )){
        isVisited[x][y] = 1;
        solve(x+1,y,arr,isVisited,path+'D',ans);
        isVisited[x][y] = 0;
    }

    // Left
    if (isSafe(x,y-1, isVisited, arr, n )){
        isVisited[x][y] = 1;
        solve(x,y-1,arr,isVisited,path+'L',ans);
        isVisited[x][y] = 0;
    }

    // Right
    if (isSafe(x,y+1, isVisited, arr, n )){
        isVisited[x][y] = 1;
        solve(x,y+1,arr,isVisited,path+'R',ans);
        isVisited[x][y] = 0;
    }

    // Up
    if (isSafe(x-1,y, isVisited, arr, n )){
        isVisited[x][y] = 1;
        solve(x-1,y,arr,isVisited,path+'U',ans);
        isVisited[x][y] = 0;
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {

    vector < string> ans;
    vector < vector < int >> isVisited(n , vector < int >(n , 0));
    string path = "";

    solve(0,0,arr,isVisited,path,ans,n);

}

int main(){
    vector < vector < int >>   arr =   {{1, 0, 0, 0},
                                        {1, 1, 0, 0},
                                        {1, 1, 0, 0},
                                        {0, 1, 1, 1}};

    int n = 4;

    
    return 0;
}