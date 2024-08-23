#include <iostream>
#include <vector>
#include <algorithm>
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

// rotate the array by 90 degree
void rotateBrute(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[j][(n - 1) - i] = matrix[i][j];
        }
    }

    matrix = ans;
}

// optimal approach - inplace algo
void rotate(vector<vector<int>> &matrix)
{
    
    // tranpose the matrix
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    printMatrix(matrix);

    // reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{

    vector<vector<int>> arr = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    rotate(arr);
    printMatrix(arr);

    return 0;
}