#include <cstdio>
#include <iostream>
using namespace std;
bool mark[100009];
int main()
{
    int k, l, m, n, d, ans=0;
    cin>>k>>l>>m>>n>>d;
    if(k==1 || l==1 || m==1 || n==1)return 0*printf("%d\n", d);
    for(int i=k; i<=d; i+=k) mark[i]=1;
    for(int i=l; i<=d; i+=l) mark[i]=1;
    for(int i=m; i<=d; i+=m) mark[i]=1;
    for(int i=n; i<=d; i+=n) mark[i]=1;
    for(int i=1; i<=d; i++)if(!mark[i])ans++;
    cout<<d-ans<<endl;
}
