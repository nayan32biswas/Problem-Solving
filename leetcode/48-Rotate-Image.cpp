#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void completeCircle(vector<vector<int>> &matrix, int pos, int n)
    {
        n = n - 1;
        for (int k = 0; k < n; k++)
        {
            swap(matrix[pos][pos + k], matrix[pos + k][pos + n]);
            swap(matrix[pos][pos + k], matrix[pos + n][pos + n - k]);
            swap(matrix[pos][pos + k], matrix[pos + n - k][pos]);
        }
    }
    void rotate(vector<vector<int>> &matrix)
    {
        for (int n = matrix.size(), i = 0; n > 0; i++, n -= 2)
        {
            completeCircle(matrix, i, n);
        }
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

    vector<vector<int>> data = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};
    // vector<vector<int>> data = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, { 15, 14, 12, 16 }};
    output(data);
    solu.rotate(data);
    puts("");
    output(data);
    return 0;
}