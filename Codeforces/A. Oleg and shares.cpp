#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, n, k, Min=INT_MAX, temp, dec;
    cin>>n>>k;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]<Min){Min = arr[i];}
        //if(!(k&1) && arr[i]&1){return puts("-1"), 0;}
    }
    bool ck=true;
    unsigned long long ans=0;
    while(ck){
        for(i=0, ck=false; i<n; i++){
            if(arr[i]>Min){
                ck = true;
                temp = arr[i]-Min;
                dec = temp/k;
                if(temp%k>0){dec++;}
                ans+=dec;
                arr[i]-=(dec*k);
            }
            if(arr[i]<Min) {
                ans++;
                Min-=k;
            }
            if(arr[i]<0 || Min<1) {
                return puts("-1"), 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
