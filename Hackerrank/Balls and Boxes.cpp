#include <iostream>
#include <cstdio>
#include <algorithm>
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
int A[101], C[101], B[101][101], ans[101000], ansI, n, m, a;
struct data{
    int value, I, J;
}arr[10009];
inline bool comp(data a, data b){
    if(a.value!=b.value) return a.value>b.value;
    if(a.I!=b.I) return a.I>b.I;
    return a.J>b.J;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, amount=0;
    scanf("%d%d", &n, &m);
    for(i=0; i<n; i++) read(A[i]), amount+=A[i];
    for(i=0; i<m; i++) read(C[i]);

    for(i=0, a; i<n; i++){
        for(j=0; j<m; j++, a++){
            read(B[i][j]);
            arr[a].value=B[i][j];
            arr[a].I=i;
            arr[a].J=j;
        }
    }
    sort(arr, arr+a, comp);
    long long ans=0;
    //for(i=0; i<a; i++)cout<<arr[i].value<<' '<<arr[i].x<<' '<<arr[i].y<<endl;
    for(i=0; i<n; i++){
        ans+=arr[i].value;
        if(C[arr[i].J]==0) ans--;
    }
    cout<<ans<<endl;
    return 0;
}
