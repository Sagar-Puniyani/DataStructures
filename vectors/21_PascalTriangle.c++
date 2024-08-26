#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (vector<int> array : matrix)
    {
        for (int element : array)
        {
            cout << element << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void printArr(vector<int> arr)
{
    for (int element : arr)
    {
        cout << element << "  ";
    }
    cout << endl;
}

// variation 1
int nCr(int n, int r)
{
    int result = 1;

    for (int i = 0; i < r; i++)
    {

        result = result * (n - i);
        result = result / (i + 1);
    }

    return result;
}

// variation 2
vector<int> nCr2(int n)
{
    vector<int> result;
    int ans = 1;
    result.push_back(ans);

    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;

        result.push_back(ans);
    }

    return result;
}

// variation 3
vector<vector<int>> nCr3(int n)
{
    vector <vector <int>> matrix;
    for (int row = 1; row <= n; row++)
    {
        matrix.push_back(nCr2(row));
    }

    return matrix;
}

int main()
{

    int ans = nCr(5, 2);

    cout << "combination : " << ans << endl;

    vector<int> result = nCr2(6);
    printArr(result);

    vector<vector<int>> matrix = nCr3(5);
    printMatrix(matrix);

    return 0;
}