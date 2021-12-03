#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int rows, columns;
    vector<vector<int>> state;

public:
    void start_storing(vector<vector<char>> &grid)
    {
        rows = grid.size(), columns = grid[0].size();
        state.resize(rows);
        for (int i = 0; i < rows; i++)
        {
            state[i].resize(columns);
            for (int coun = 0, j = columns - 1; j >= 0; j--)
            {
                if (grid[i][j] == '0')
                    coun = 0;
                else
                    coun++;
                state[i][j] = coun;
            }
        }
        // for(auto itit : state){
        //     for(auto it : itit)
        //         cout<<it<<" ";
        //     puts("");
        // }
    }
    int biggestTable(vector<vector<char>> &grid)
    {
        // Put code here
        int offices = -1;
        start_storing(grid);
        for(int k=0; k<rows; k++){
            for (int i = 0; i < columns; i++)
            {
                for (int j = k, Min = state[j][i]; j < rows; j++)
                {
                    if(state[j][i]==0)break;
                    Min = min(Min, state[j][i]);
                    // cout<<Min<<" ";
                    offices = max(offices, (j-k + 1) * Min);
                }
                // cout<<endl<<offices<<endl;
            }
            // puts("");
        }
        return offices;
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);
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
    cout << solution.biggestTable(vect);

    return 0;
}