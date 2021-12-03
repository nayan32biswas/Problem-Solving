#include <bits/stdc++.h>
using namespace std;
typedef vector< vector<bool>> vecvec;

#define row 4
#define col 4
void create(vecvec &board){
    board.resize(row+1);
    for (int i = 0; i < row+1; i++)
        board[i].resize(col);
}
void clear(vecvec &board)
{
    for (int i = 0; i < row; i++)
    {
        bool cl = true;
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == false)
            {
                cl = false;
                break;
            }
        }
        if (cl)
        {
            for (int j = 0; j < col; j++)
            {
                board[i][j] = false;
                cout<<i<<","<<j<<"\t";
                for (int k = i; k < row; k++)
                {
                    board[k][j] = board[k + 1][j];
                }
            }
            puts("");
        }
    }
}
int coun(vecvec &board){
    for()
}
void show(vecvec &board)
{
    for (auto it : board)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        puts("");
    }
    puts("");
}
void best_step_zero(){

}
void best_step_one(){

}
int main()
{
    vecvec board;
    create(board);
    board[0][0] = true, board[0][1] = true, board[0][2] = true, board[0][3] = true;
    board[1][0] = true, board[1][1] = true, board[1][3] = true;
    board[2][0] = true, board[2][1] = true, board[2][2] = true, board[2][3] = true;
    show(board);
    clear(board);
    show(board);
    return 0;
}