#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y;
    long long arr[104];
    int n, m, test, i;
    char c;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++)scanf("%lld", &arr[i]);
        for(int j=0; j<m; j++){
            cin.ignore();
            cin>>c;
            if(c=='S'){
                scanf("%d", &x);
                for(i=0; i<n; i++)arr[i]+=x;
            }
            else if(c=='M'){
                scanf("%d", &x);
                for(i=0; i<n; i++)arr[i]*=x;
            }
            else if(c=='D'){
                scanf("%d", &x);
                for(i=0; i<n; i++)arr[i]/=x;
            }
            else if(c=='R')reverse(arr, arr+n);
            else if(c=='P'){
                scanf("%d%d", &x, &y);
                swap(arr[x], arr[y]);
            }
        }
        printf("Case %d:\n", t);
        for(i=0; i<n; i++){
            if(i) printf(" ");
            printf("%lld", arr[i]);
        }puts("");
    }
}
