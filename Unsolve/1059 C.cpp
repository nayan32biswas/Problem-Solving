#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<4){
        if(n==1)puts("1");
        else if(n==2)puts("1 2");
        else puts("1 1 3");
        return 0;
    }
    for(int i=1; i<=n; i+=2) printf("1 ");
    if(n&1) n--;
    for(int i=2; i<n; i+=2){
        printf("2 ");
    }
    cout<<n<<endl;
    return 0;
}
