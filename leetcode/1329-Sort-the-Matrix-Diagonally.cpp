#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        int diagonalLength = max(m, n);
        int temp[diagonalLength];

        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = m, j = 0, len, x, y;;)
        {
            if (i > 0)
                i--;
            else
            {
                j++;
                if (j == n)
                    break;
            }
            printf("%d %d\n", i, j);

            for (x = i, y = j, len = 0; x < m && y < n; x++, y++)
                temp[len++] = mat[x][y];
            sort(temp, temp + len);

            for (x = i, y = j, len = 0; x < m && y < n; x++, y++)
                ans[x][y] = temp[len++];
        }
        return ans;
    }
};
void output(vector<vector<int>> &matrix)
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

    vector<vector<int>> data = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};

    data = solu.diagonalSort(data);

    output(data);

    return 0;
}
