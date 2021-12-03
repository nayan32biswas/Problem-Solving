#include <bits/stdc++.h>
using namespace std;
long long k, n, ans;
unsigned long long arr[65];
void store(){
    long long POW = 1;
    for(int i=0; i<64; i++) arr[i] = (POW*=2)-1;
}
int main()
{
    store();
    cin>>n>>k;
    if(n==1) return puts("1"), 0;
    if(k==1) return cout<<n<<endl ,0;
    for(int i=63; i>=0; i--){
        if(n>arr[i]){
            cout<<arr[i+1]<<endl;
            return 0;
        }
    }
}
