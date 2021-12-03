#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int num[111][111], n;
int call(int i)
{
    int j, sum, sum1, Max=0;
    for(j=0; j<n; j++){
        sum=num[i][j]+num[i][j+1]+num[i+1][j]+num[i+1][j+1]+num[i+2][j]+num[i+2][j+1];
        sum1=num[i][j]+num[i+1][j]+num[i][j+1]+num[i+1][j+1]+num[i][j+2]+num[i+1][j+2];
        sum=max(sum, sum1);
        Max=max(Max, sum);
    }
    return Max;
}
int main()
{
    freopen("Input.txt", "r", stdin);
    int i, j, sum, ans=0;
    while(cin>>n){
        ans=0;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d", &num[i][j]);
            }
        }
        n-=2;
        for(i=0; i<n; i++){
            sum=call(i);
            if(sum>ans) ans=sum;
        }
        cout<<ans<<endl;
    }
    return 0;
}

