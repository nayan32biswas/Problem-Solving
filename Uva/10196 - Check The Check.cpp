#include <bits/stdc++.h>
using namespace std;
string print[]={"black king is in check.", "white king is in check.", "no king is in check."};
struct data{
    char stage[9][9];
    int black_x=0, black_y=0, white_x=0, white_y=0;
}temp, cle;
vector<data>All_board;
bool ck(int x_axis, int y_axis){
    if(x_axis<0 || y_axis<0 || x_axis>8 || y_axis>8) return false;
    return true;
}
bool knight(char c, char s[][9], int x, int y){
    if(ck(x+2, y+1)==true && s[x+2][y+1]==c) return true;
    if(ck(x+2, y-1)==true && s[x+2][y-1]==c) return true;
    if(ck(x-2, y+1)==true && s[x-2][y+1]==c) return true;
    if(ck(x-2, y-1)==true && s[x-2][y-1]==c) return true;
    if(ck(x+1, y+2)==true && s[x+1][y+2]==c) return true;
    if(ck(x-1, y+2)==true && s[x-1][y+2]==c) return true;
    if(ck(x+1, y-2)==true && s[x+1][y-2]==c) return true;
    if(ck(x-1, y-2)==true && s[x-1][y-2]==c) return true;
    return false;
}
bool rook(char c, char s[][9], int x, int y){
    int i, j;
    for(i=x+1, j=y; ck(i, j); i++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x-1, j=y; ck(i, j); i--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x, j=y+1; ck(i, j); j++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x, j=y-1; ck(i, j); j--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    } return false;
}
bool queen(char c, char s[][9], int x, int y){
    int i, j;
    for(i=x+1, j=y; ck(i, j); i++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x-1, j=y; ck(i, j); i--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x, j=y+1; ck(i, j); j++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x, j=y-1; ck(i, j); j--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x-1, j=y+1; ck(i, j); i--, j++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x-1, j=y-1; ck(i, j); i--, j--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x+1, j=y+1; ck(i, j); i++, j++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x+1, j=y-1; ck(i, j); i++, j--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    } return false;
}
bool bishop(char c, char s[][9], int x, int y){
    int i, j;
    for(i=x-1, j=y+1; ck(i, j); i--, j++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x-1, j=y-1; ck(i, j); i--, j--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x+1, j=y+1; ck(i, j); i++, j++)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    }
    for(i=x+1, j=y-1; ck(i, j); i++, j--)if(s[i][j]!='.'){
        if(s[i][j]==c) {return true;} break;
    } return false;
}
void solve(data &board){
    int i, j;
    char c, c1;
    c = 'N', c1 = 'n';
    if(knight(c, board.stage, board.black_x, board.black_y)){
        cout<<print[0]<<endl;return;
    }
    else if(knight(c1, board.stage, board.white_x, board.white_y)){
        cout<<print[1]<<endl;return;
    }
    c = 'R', c1 = 'r';
    if(rook(c, board.stage, board.black_x, board.black_y)){
        cout<<print[0]<<endl;return;
    }
    else if(rook(c1, board.stage, board.white_x, board.white_y)){
        cout<<print[1]<<endl;return;
    }
    c = 'Q', c1 = 'q';
    if(queen(c, board.stage, board.black_x, board.black_y)){
        cout<<print[0]<<endl;return;
    }
    else if(queen(c1, board.stage, board.white_x, board.white_y)){
        cout<<print[1]<<endl;return;
    }
    c = 'B', c1 = 'b';
    if(bishop(c, board.stage, board.black_x, board.black_y)){
        cout<<print[0]<<endl;return;
    }
    else if(bishop(c1, board.stage, board.white_x, board.white_y)){
        cout<<print[1]<<endl;return;
    }
    c = 'P', c1 = 'p';
    i = board.black_x+1, j = board.black_y;
    if((ck(i, j-1) && board.stage[i][j-1]==c) || (ck(i, j+1) && board.stage[i][j+1]==c)){
        cout<<print[0]<<endl;return;
    }
    i = board.white_x-1, j = board.white_y;
    if((ck(i, j-1) && board.stage[i][j-1]==c1) || (ck(i, j+1) && board.stage[i][j+1]==c1)){
        cout<<print[1]<<endl;return;
    }
    cout<<print[2]<<endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, len;
    while(true){
        for(i=0; i<8; i++){
            scanf("%s", temp.stage[i]);
            for(j=0; j<8; j++){
                if(temp.stage[i][j]=='k'){
                    temp.black_x = i, temp.black_y = j;
                }
                else if(temp.stage[i][j]=='K'){
                    temp.white_x = i, temp.white_y = j;
                }
            }
        }
        if(temp.white_x==0 && temp.white_y==0 && temp.black_x==0 && temp.black_y==0)break;
        All_board.push_back(temp);
        temp = cle;
    }
    len = All_board.size();
    for(i=0; i<len; i++){
        printf("Game #%d: ", i+1);
        solve(All_board[i]);
    }
    return 0;
}
