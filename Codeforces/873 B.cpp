#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int n, ans ;
string s;
void to_n(int i) {
    int one = 0, zero = 0;
    for(; i<n; i++) {
        if(s[i]=='0') zero++;
        else if(s[i]=='1') one++;
        if(zero==one) {
            arr[i] = max(arr[i], zero<<1);
            ans = max(arr[i], ans);
        }
    }
}
void from_n(int t){
    int one = 0, zero = 0;
    for(int i=n-1; i>=t; i--){
        if(s[i]=='0') zero++;
        else if(s[i]=='1') one++;
        if(zero==one) {
            arr[i] = max(arr[i], zero<<1);
            ans = max(arr[i], ans);
        }
    }
}
int main() {
    cin>>n>>s;
    bool ck1 = true, ck = true;
    for(int i=0; i<n; i++) {
        if(ck1 && s[i]=='1') to_n(i), ck1 = false;
        if(ck && s[i]=='0') to_n(i), ck = false;
        if(!ck && !ck1) break;
    }
    if(ans==0) return puts("0"), 0;

    for(int i=1; i<n; i++) {
        if(s[i]!=s[i-1]) {
            from_n(i);
            from_n(i-1);
        }
    }

    ck = ck1 = true;
    for(int i=n-1; i>=0; i--){
        if(ck1 && s[i]=='1') to_n(i), ck1 = false;
        if(ck && s[i]=='0') to_n(i), ck = false;
        if(!ck && !ck1) break;
    }
    for(int i=n-1; i>0; i--){
        if(s[i]!=s[i-1]) {
            from_n(i);
            from_n(i-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
