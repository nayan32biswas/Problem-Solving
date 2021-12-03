#include<bits/stdc++.h>
using namespace std;
#define Size 101
vector<string>strArr;
int pos[Size], len[Size];
void solve(){
    memset(pos, 0, sizeof(pos));
    int element = strArr.size();
    bool check = true;
    while(check){
        check = false;
        for(int i=element-1; i>=0; i--){
            if(pos[i]<len[i]){
                check = true;
                printf("%c", strArr[i][pos[i]]);
                pos[i]++;
            }
            else printf(" ");
        }
        if(check) puts("");
    }
}
int main()
{
    //freopen("Input.txt", "r", stdin);
    string str;
    int i=0;
    while(getline(cin, str)){
        strArr.push_back(str);
        len[i++] = str.size();
    }
    solve();
    return 0;
}
