#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Find(ll n, ll k){
    ll eat = 0;
    while(n>=k){
        n -= k;
        if(n>9){
            n -= (n/10);
        }
        eat += k;
    }
    if(n>0) eat += n;
    return eat;
}

int main() {
    ll n, k, eat;
    ll Start, End, mid;
    cin>>n;
    ll half = (n+1)/2, ans = 0;
    Start = 1, End = (n/2)+1;
    while(Start<End){
        mid = (Start+End)/2;
        eat = Find(n, mid);
        if(eat>half) End = mid-1;
        else Start = mid+1;
    }
    End = Start+5;
    for(Start=max(Start-3, ll(1)); Start<End; Start++){
        if(Find(n, Start)>=half){
            cout<<Start<<endl;
            return 0;
        }
    }
    return 0;
}
