#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull a, b, num, x;
int len;
char mess[1000009];
bool mark[1000009], ck;
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, mid;
    scanf("%s", mess);
    cin>>a>>b;
    len = strlen(mess);
    for(i=len-1, num=0, x=1, ck=false; i>0; i--){
        num = ((mess[i]-'0')*x + num)%b;
        x=(x*10)%b;
        if(mess[i]!='0') ck=true;
        if(ck && num==0) mark[i-1]=true, ck=false;
    }

    for(i=0, num=0; i<len; i++){
        num = (num*10+(mess[i]-'0'))%a;
        if(num==0 && mark[i]==true) {mid=i+1; break;}
    }
    if(i==len) return puts("NO"), 0;

    puts("YES");
    for(i=0; i<mid; i++) printf("%c", mess[i]);puts("");
    for(; i<len; i++) printf("%c", mess[i]);puts("");
    return 0;
}
