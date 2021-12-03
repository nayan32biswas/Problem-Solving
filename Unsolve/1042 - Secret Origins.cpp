#include <bits/stdc++.h>
using namespace std;
unsigned arr[32], arr2[33], len;
char s[50];
unsigned toDec(){
    unsigned ans=0;
    for(int i=0; i<len; i++)if(s[i]==1)ans+=(1<<i);
    return ans;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    unsigned test, N, pos, many;
    unsigned i, ans;
    for(i=0; i<32; i++) arr[i] = 1<<i;
    cin>>test;
    bool ck;
    for(int t=1; t<=test; t++){
        cin>>N;
        for(i=0; i<33; i++) s[i]=0;
        printf("Case %d: ", t);
        for(i=0; i<31; i++)if(arr[i]==N) break;
        if(i!=31) {
            cout<<arr[++i]<<endl;
            continue;
        }
        if(N<200){
            many = 0;
            int n = N;
            while(n>0){
                if(n&1) many++;
                n>>=1;
            }
            for(i=N+1; ; i++){
                N = i, len=0;
                while(N>0){
                    if(N&1) len++;
                    N>>=1;
                }
                if(len==many) {
                    cout<<i<<endl;
                    break;
                }
            }
            continue;
        }
        else {
            len = 0;
            unsigned n = N+1;
            while(N>0){
                s[len++] = N&1;
                N>>=1;
            }
            len++;
            //for(i=0; i<len; i++) printf("%d ", s[i]); puts("");
            for(many=0, i=0; i<len; i++) if(s[i]==1) many++;
            if(s[0]==0){
                for(s[0]=1, i=1; i<len; i++) if(s[i]==1) break;
                for(; i<len; i++){
                    if(s[i]==1) s[i]=0;
                    else {
                        s[i]=1;
                        break;
                    }
                }
            }
            else {
                for(i=0; i<len-1; i++)if(s[i]==1 && s[i+1]==0){
                    s[i]=0, s[i+1]=1;
                    break;
                }
            }
            //for(i=0; i<len; i++) printf("%d ", s[i]); puts("");
            ans = toDec();
            for(i=max((ans-100), n); i<(ans+100); i++){
                N = i, len=0;
                while(N>0){
                    if(N&1) len++;
                    N>>=1;
                }
                if(len==many)break;

            }
            cout<<i<<endl;
        }
    }
    return 0;
}

/*
0 0 0 1 1 0 0 1 1 1 1 0 1 1 0
0 0 0 1 0 1 0 1 1 1 1 0 1 1 0
*/
