#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &sudoku, int val){
    int n = sudoku.size();
    for ( int i=0; i<n; i++){
        if (sudoku[row][i] == val){
            return false;
        }
        if (sudoku[i][col] == val){
            return false;
        }
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &sudoku)
{
    int n = sudoku[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {

            if (sudoku[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, sudoku, val))
                    {
                        sudoku[row][col] = val;

                        bool restPossibleSolution = solve(sudoku);
                        if (restPossibleSolution)
                        {
                            return true;
                        }
                        else
                        {
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    solveSudoku(sudoku);
    return 0;
}