#include <bits/stdc++.h>
using namespace std;
#define fix fixed<<setprecision(7)
#define Size 100
int arr[Size];
int main()
{
    double ans = 999999, a, b;
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        ans = min(ans, a/b);
    }
    cout<<fix<<m*ans<<endl;

    return 0;
}
