#include<iostream>
using namespace std;
int main() {
    int n, k, num, ans=0, i;
    cin>>n>>k;
    for(i=1; i<=n; i++){
        cin>>num;
        if(i==k){
            ans = num;
        }
        if( (i>k && ans>num) || num<1){
            break;
        }
    }
    i--;
    if(i<0)i=0;
    cout<<i<<endl;
    return 0;
}
