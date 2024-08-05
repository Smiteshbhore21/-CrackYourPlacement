#include <iostream>
#include <vector>
using namespace std;

void floodFillUtil(vector<vector<char>> &mat, int x, int y, char prevV, char newV)
{
    if (x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size())
        return;
    if (mat[x][y] != prevV)
        return;

    mat[x][y] = newV;

    floodFillUtil(mat, x + 1, y, prevV, newV);
    floodFillUtil(mat, x - 1, y, prevV, newV);
    floodFillUtil(mat, x, y + 1, prevV, newV);
    floodFillUtil(mat, x, y - 1, prevV, newV);
}

int replaceSurrounded(vector<vector<char>> &mat)
{
    int M = mat.size();
    int N = mat[0].size();

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-';

    for (int i = 0; i < M; i++) // Left side
        if (mat[i][0] == '-')
            floodFillUtil(mat, i, 0, '-', 'O');
    for (int i = 0; i < M; i++) // Right side
        if (mat[i][N - 1] == '-')
            floodFillUtil(mat, i, N - 1, '-', 'O');
    for (int i = 0; i < N; i++) // Top side
        if (mat[0][i] == '-')
            floodFillUtil(mat, 0, i, '-', 'O');
    for (int i = 0; i < N; i++) // Bottom side
        if (mat[M - 1][i] == '-')
            floodFillUtil(mat, M - 1, i, '-', 'O');

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
}

int main()
{
    vector<vector<char>> mat = {
        {'X', 'O', 'X', 'O', 'X', 'X'},
        {'X', 'O', 'X', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'X'},
        {'O', 'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X', 'O'},
        {'O', 'O', 'X', 'O', 'O', 'O'},
    };
    replaceSurrounded(mat);

    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
