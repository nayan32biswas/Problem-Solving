#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}
int arr[100009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, hit, t, i, ans;
    scanf("%d%d%d", &n, &hit, &t);
    for(i=0; i<n; i++)read(arr[i]);
    sort(arr, arr+n);
    for(i=0, ans=0; i<n && t>0; ){
        if(arr[i]>0) arr[i]-=hit, t--;
        else {ans++,i++;}
    }
    if(arr[i]<1) ans++;
    cout<<ans<<endl;
    //for(i=0; i<n; i++) cout<<arr[i]<<' ';cout<<endl;
    return 0;
}
