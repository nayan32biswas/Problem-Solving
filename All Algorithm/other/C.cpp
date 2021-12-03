#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string ans = "";
    cin>>n;
    if(n==0){
        return 0*puts("01");
    }
    if(n<=9){
        return 0*printf("%d\n", n);
    }
    for(int i=9; i>=2; i--){
        while(n%i==0){
            n/=i;
            ans += char(i+'0');
        }
    }
    if(n>9)puts("-1");
    else{
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    return 0;
}