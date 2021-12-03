#include <bits/stdc++.h>
using namespace std;
#define Size 10005
string s;
int x, y;
void U(){y++;}
void D(){y--;}
void L(){x--;}
void R(){x++;}
int main(){
    int n, ans=0;
    cin>>n;
    cin>>s;
    for(auto it : s){
        if(it=='U') U();
        if(it=='D') D();
        if(it=='L') L();
        if(it=='R') R();
    }
    x = abs(x);
    y = abs(y);
    printf("%d\n", n-(x+y));
    return 0;
}
