#include <bits/stdc++.h>
using namespace std;
#define I 305
int arr[400], candle[10000];
bool ck;
void Set(int num, int t){
    num+=I, t+=num;
    if(num<0) return;
    candle[num-1]=-1;
    for(int i=num; i<t; i++) {
        if(candle[i]!=-1) candle[i]++, ck=true;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, m, t, r, ans=0, num, R;
    cin>>m>>t>>r;
    for(i=0; i<m; i++)scanf("%d", &arr[i]);
    ans=r;
    num = arr[0];
    for(i=num, R=r; R; i--, R--)Set(i, t);

    //for(i=I-2; i<=I+num+5; i++) cout<<candle[i]<<' '; cout<<endl;

    if(m==1) {
        if(candle[num+I]==r) cout<<r<<endl;
        else puts("-1");
        return 0;
    }

    for(i=0; i<m; i++){
        num = arr[i], R=r;
        while((abs(num-arr[i])<t) && candle[arr[i]+I]!=r){
            ck=false;
            Set(num, t);
            if(ck) ans++;
            num--;
        }
        if(candle[arr[i]+I]!=r) return puts("-1"), 0;
    }
    if(candle[arr[m-1]+I]!=r) return puts("-1"), 0;
    cout<<ans<<endl;
}
