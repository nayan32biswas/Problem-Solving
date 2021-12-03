#include <bits/stdc++.h>
using namespace std;
#define Size -9999999
map<int, bool>SSS;

void parfect(){
    long long n=0, x;
    while(n*n<1000009) {
        x = n;
        SSS[x*x] = 1;
        x = -n;
        SSS[x*x] = 1;
        n++;
    }
}
bool is(int n){

}
int main(){
    int n, x, Max = Size, Min = -Size;
    parfect();
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x;
        if(!SSS[x]){
            Max = max(Max, x);
        }
        else Min = min(Min, x);
    }
    if(Max==Size){
        cout<<Min<<endl;
    }
    else cout<<Max<<endl;
    return 0;
}
