#include <bits/stdc++.h>
using namespace std;
#define Size 5000005
#define mod 1000000007
char str[Size];
long long big_mod(long long base, long long po) {
    long long ans=1;
    while(po>0) {
        if(po&1)
            ans = (ans*base)%mod;
        base=(base*base)%mod;
        po>>=1;
    }
    return ans%mod;
}
int len;
bool check;
long long ans;
void solve(int i, int last, int n) {
    long long each = 0;
    //printf("Entry  %d  %d  %d   %d\n", i, last, len, n);
    if(n>1) {
        //puts("In n > 1");
        each = (big_mod(2, n-1)*3)%mod;
        if(last<len && each>2) {
            each -= 2;
        }
        if(i>=0 && each>2) {
            each -= 2;
        }
    } else if(n==1) {
        //puts("In n = 1");
        if(i==-1 && last==len) {
            each = 3;
            //puts("3");
        }
         else if((i>=0 && (str[i]==str[last] || last==(len))) || i<0) {
            //puts("2");
            each = 2;
        } else if(i>=0 && str[i]!=str[last]) {
            each = 1;
            //puts("1");
        }
    }
    if(each>0){
        check = true;
        ans = (ans*each)%mod;
    }
    //printf("exit %d %d  %lld %lld\n\n", i, last, each, ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%s", str);
        check = false;

        ans = 1;
        len = strlen(str);
        int last, n, i=len;
        n = 0;
        last = i;
        i--;
        while(i>=0 && str[i]=='W') {
            i--, n++;
        }
        solve(i, last, n);
        for(; i>=0; i--) {
            if(str[i]!='W' && i>0) {
                n = 0;
                last = i;
                i--;
                while(i>=0 && str[i]=='W') {
                    i--, n++;
                }
                solve(i, last, n);
                i++;
            }

        }
        if(check==false) ans = 0;
        printf("Case %d: %lld\n", t, ans%mod);
        //puts("\n\n");
    }
    return 0;
}
