#include <bits/stdc++.h>
using namespace std;
int arr[100010];
int temp;

int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, n, m, ans=0, sum=0, Max=0, last;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &temp);
        sum+=temp;
    }

    scanf("%d", &m);
    for(i=0; i<m; i++){
        scanf("%d%d", &j, &last);
        for(; j<=last; j++) arr[j]=1;
        Max = max(Max, last);
    }
    for(i=1, temp=0; i<=Max; i++){
        if(i>=sum && arr[i]==1) {
            return printf("%d\n", i), 0;
        }
    }
    puts("-1");
}
