#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<char>> graph;
    int height, width;

public:
    bool is_valid(vector<vector<char>> &grid, int x, int y)
    {
        return x < height && x >= 0 && y < width && y >= 0 && grid[x][y] == '1';
    }
    void dfs(vector<vector<char>> &grid, int RR[], int CC[], int x, int y)
    {
        if (grid[x][y] != '1')
            return;
        grid[x][y] = '0';
        int xx, yy, i;
        for (i = 0; i < 4; i++)
        {
            xx = x + RR[i], yy = y + CC[i];
            if (is_valid(grid, xx, yy))
            {
                dfs(grid, RR, CC, xx, yy);
            }
        }
    }

    int numOffices(vector<vector<char>> &grid)
    {
        height = grid.size(), width = grid[0].size();
        int res, RR[] = {0, 1, -1, 0}, CC[] = {1, 0, 0, -1};
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++){
                if (grid[i][j] == '1')
                {
                    dfs(grid, RR, CC, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};

int main()
{
    // Parsing input here
    int rows, columns;

    cin >> rows;
    cin >> columns;

    vector<vector<char>> vect(rows);

    for (int i = 0; i < rows; i++)
    {
        vect[i] = vector<char>(columns);
        for (int j = 0; j < columns; j++)
        {
            cin >> vect[i][j];
        }
    }

    Solution solution;
    cout << solution.numOffices(vect);

    return 0;
}
