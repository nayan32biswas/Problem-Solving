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
long long sum, sum1, sum2;
struct data{
    int k, l, dis;
}arr[100009];

bool comp(data a, data b){
    if(a.l!=b.l) return a.l>b.l;
    if(a.k!=b.k) return a.k>b.k;
    return a.dis>b.dis;
}
bool compk(data a, data b){
    if(a.k!=b.k) return a.k>b.k;
    if(a.l!=b.l) return a.l>b.l;
    return a.dis>b.dis;
}
bool cod(data a, data b){
    if(a.dis!=b.dis) return a.dis>b.dis;
    if(a.k!=b.k) return a.k>b.k;
    return a.l>b.l;
}
long long check(int n, int f){
    long long sum=0;
    int i;
    for(i=0; i<f; i++)sum+=min(arr[i].k<<1, arr[i].l);
    for(i=f; i<n; i++)sum+=min(arr[i].k, arr[i].l);
    return sum;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, f, i;
    scanf("%d%d", &n, &f);
    for(i=0; i<n; i++){
        read(arr[i].k);
        read(arr[i].l);
        arr[i].dis = abs(arr[i].k-arr[i].l);
    }
    long long sum, sum1, sum2;
    sort(arr, arr+n, comp);
    sum = check(n, f);
    sort(arr, arr+n, compk);
    sum1 = check(n, f);
    sort(arr, arr+n, cod);
    sum2 = check(n, f);
    cout<<max(sum, max(sum1, sum2))<<endl;
}
