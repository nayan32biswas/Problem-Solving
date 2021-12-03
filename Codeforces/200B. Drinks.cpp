#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    double sum;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        sum+=x;
    }
    sum/=n;
    cout<<fixed<<setprecision(12)<<sum<<endl;
    return 0;
}
