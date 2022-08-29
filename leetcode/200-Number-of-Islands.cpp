#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int R[4] = {0, 1, 0, -1};
    int C[4] = {1, 0, -1, 0};
    int m, n, x, y;
    void fillLand(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++)
        {
            x = i + R[k], y = j + C[k];
            if (x >= 0 && x < m and y >= 0 && y < n && grid[x][y] == '1')
            {
                fillLand(grid, x, y);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0, j; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    fillLand(grid, i, j);
                }
            }
        }
        return ans;
    }
};
void output(vector<vector<char>> &matrix)
{
    for (auto it : matrix)
    {
        for (auto inner : it)
            cout << inner << "\t ";
        puts("");
    }
}
int main()
{
    Solution solu = Solution();

    vector<vector<char>> data = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    cout<<solu.numIslands(data)<<endl;

    output(data);

    return 0;
}
