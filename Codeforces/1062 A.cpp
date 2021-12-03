#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, arr[1001], ans=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    for(int i=1; i<n-1; i++)
    {
        if(arr[i-1]+1==arr[i] && arr[i]==arr[i+1]-1){
            int coun = 0;
            //cout<<i<<" ";
            if(arr[i]==2) coun++;
            for(; i<n-1; i++){
                if(arr[i-1]+1==arr[i] && arr[i]==arr[i+1]-1){
                    coun++;
                }
                else break;
            }
            //cout<<i<<" "<<coun<<endl;
            if(i==n-1 && arr[n-2]==arr[n-1]-1 && arr[n-1]==1000){
                coun++;
            }
            ans = max(coun, ans);
        }
    }
    if(n>2 && ans==0 && ((arr[0]==1 && arr[1]==2) || (arr[n-2]==999 && arr[n-1]==1000))){
       ans++;
    }
    if(n==2 && arr[0]==arr[1]-1 && (arr[0]==1 || arr[1]==1000)){
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
