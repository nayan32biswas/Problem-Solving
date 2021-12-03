#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, x, ans=1;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        if(k%x==0) ans = max(ans, x);
    }
    cout<<(k/ans)<<endl;
}
