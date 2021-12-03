#include <bits/stdc++.h>
using namespace std;
#define Size 105
int arr[Size][Size];
int main()
{
    //freopen("input.txt", "r", stdin);
    int H, W, x, y;
    long long ans=0;
    cin>>H>>W;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>arr[i][j];
            ans+=(arr[i][j]*6);
            if(arr[i][j]>1) ans-=2*(arr[i][j]-1);
        }
    }
    for(int i=0; i<H; i++){
        x = 0;
        for(int j=1; j<W; j++){
            x+=min(arr[i][j], arr[i][j-1])*2;
        }
        ans-=x;
    }
    for(int i=0; i<W; i++){
        x = 0;
        for(int j=1; j<H; j++){
            x+=min(arr[j][i], arr[j-1][i])*2;
        }
        ans-=x;
    }
    cout<<ans<<endl;
    return 0;
}
