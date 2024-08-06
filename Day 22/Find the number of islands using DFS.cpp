#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &M, int i, int j)
{
    if ((i >= 0 && i < M.size() && j >= 0 && j < M[0].size()) && M[i][j] == 1)
    {
        M[i][j] = 0;
        DFS(M, i + 1, j);
        DFS(M, i, j + 1);
        DFS(M, i - 1, j);
        DFS(M, i, j - 1);
        DFS(M, i + 1, j + 1);
        DFS(M, i - 1, j - 1);
        DFS(M, i + 1, j - 1);
        DFS(M, i - 1, j + 1);
    }
    return;
}

int countIslands(vector<vector<int>> &M)
{
    int count = 0;
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[0].size(); j++)
        {
            if (M[i][j] == 1)
            {
                count++;
                DFS(M, i, j);
            }
        }
    }
    return count;
}


int main()
{
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M);
    return 0;
}
