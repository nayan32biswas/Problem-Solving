#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
int row, clm;
char s[303][303];
struct data{
    bool all=false;
    int dis1=0, dis2=0, dis3=0;
}arr[303][303];
bool position(int i, int j){
    if(i>=row || j>=clm) return false;
    if(i<0 || j<0) return false;
    return true;
}
bool Check2(int k, int x, int y){
    if(arr[x][y].all) return false;
    if(k==0 && arr[x][y-1].all) return false;
    if(k==1 && arr[x][y+1].all) return false;
    if(k==2 && arr[x-1][y].all) return false;
    if(k==3 && arr[x+1][y].all) return false;
    return true;
}
bool Check3(int k, int x, int y){
    if(arr[x][y].all) return false;
    if(k==0 && (arr[x][y-1].all || arr[x][y-2].all)) return false;
    if(k==1 && (arr[x][y+1].all || arr[x][y+2].all)) return false;
    if(k==2 && (arr[x-1][y].all || arr[x-2][y].all)) return false;
    if(k==3 && (arr[x+1][y].all || arr[x+2][y].all)) return false;
    return true;
}
int one_i[]={0, 0, 1, -1};
int one_j[]={1, -1, 0, 0};
int two_i[]={0, 0, 2, -2};
int two_j[]={2, -2, 0, 0};
int three_i[]={0, 0, 3, -3};
int three_j[]={3, -3, 0, 0};
void bfs(ppi past){
    int i, j, x, y, ans;
    queue<ppi>Q;
    Q.push(past);
    bool ck=true;
    while(!Q.empty()){
        past = Q.front(); Q.pop();
        i = past.first, j = past.second;

        if(ck || arr[i][j].dis3>0)for(int k=0; k<4; k++){ /// this line for one step.
            x=i+one_i[k], y=j+one_j[k];
            past.first=x, past.second = y;
            if(position(x, y) && arr[x][y].dis1==0 && arr[x][y].all==false){
                arr[x][y].dis1 = arr[i][j].dis3+1; Q.push(past);
            }
        }
        if(arr[i][j].dis1>0)for(int k=0; k<4; k++){ /// this line for two step.
            x=i+two_i[k], y=j+two_j[k];
            past.first=x, past.second = y;
            if(position(x, y) && arr[x][y].dis2==0 && Check2(k, x, y)){
                arr[x][y].dis2 = arr[i][j].dis1+1; Q.push(past);
            }
        }
        if(arr[i][j].dis2>0)for(int k=0; k<4; k++){ /// this line for three step.
            x=i+three_i[k], y=j+three_j[k];
            past.first=x, past.second = y;
            if(position(x, y) && arr[x][y].dis3==0 && Check3(k, x, y)){
                arr[x][y].dis3 = arr[i][j].dis2+1; Q.push(past);
            }
        }
        ck = false;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, j, p, q, Max=INT_MAX, ans;
    scanf("%d", &test);
    for(int t=0; t<test; t++){
        scanf("%d%d",&row, &clm);
        for(i=0; i<row; i++){
            for(j=0; j<clm; j++){
                arr[i][j].all=false;
                arr[i][j].dis1=0;
                arr[i][j].dis2=0;
                arr[i][j].dis3=0;
            }
        }
        ppi past;
        for(i=0; i<row; i++){
            scanf("%s", s[i]);
            for(j=0; j<clm; j++){
                if(s[i][j]=='#') arr[i][j].all=true;
                if(s[i][j]=='E') p=i, q=j;
                else if(s[i][j]=='S'){
                    past.first=i, past.second=j;
                }
            }
        }
        bfs(past);
        i = arr[p][q].dis1>0 ? arr[p][q].dis1 : Max;
        j = arr[p][q].dis2>0 ? arr[p][q].dis2 : Max;
        ans = arr[p][q].dis3>0 ? arr[p][q].dis3 : Max;
        ans = min(ans, min(i, j));
        if(ans!=Max) printf("%d\n", ans);
        else puts("NO");
    }
    return 0;
}
