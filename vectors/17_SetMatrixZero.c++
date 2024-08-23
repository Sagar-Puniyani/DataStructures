#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (auto arr : matrix)
    {
        for (int item : arr)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// this the brute approach
void markrow(vector<vector<int>> &arr, int row)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        if (arr[row][i] != 0)
        {
            arr[row][i] = -1;
        }
    }
}
void markcol(vector<vector<int>> &arr, int col)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i][col] != 0)
        {
            arr[i][col] = -1;
        }
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                markrow(matrix, i);
                markcol(matrix, j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void setZeroBetter(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    // setZeroes(matrix);
    // printMatrix(matrix);

    cout << "Better Solution : " << endl;
    setZeroBetter(matrix);
    printMatrix(matrix);

    return 0;
}