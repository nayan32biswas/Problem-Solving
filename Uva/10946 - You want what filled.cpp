#include <bits/stdc++.h>
using namespace std;
struct data{
    int first;
    char second;
    inline bool operator <(const data x)const{
        if(x.first==first) return x.second>second;
        return x.first<first;
    }
}that;
vector< data > myarr;

char flod[55][55], c;
int row, clm;

int FF(int i, int j) {
    if(i<0 || j<0 || i>=row || j>=clm)
        return 0;
    if(flod[i][j]!=c) return 0;
    flod[i][j]='.';
    int ans=1;
    ans += FF(i-1, j);
    ans += FF(i, j-1);
    ans += FF(i, j+1);
    ans += FF(i+1, j);
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int i, j, len, t=1;
    while(scanf("%d%d", &row, &clm)==2 && (row && clm)) {
        myarr.clear();
        for(i=0; i<row; i++)scanf("%s", flod[i]);
        for(i=0; i<row; i++) {
            for(j=0; j<clm; j++){
                if(flod[i][j]!='.'){
                    c = flod[i][j];
                    that.second = c;
                    that.first = FF(i, j);
                    myarr.push_back(that);
                }
            }
        }
        sort(myarr.begin(), myarr.end());
        printf("Problem %d:\n", t++);
        len = myarr.size();
        for(i=0; i<len; i++){
            printf("%c %d\n", myarr[i].second, myarr[i].first);
        }
    }
    return 0;
}
