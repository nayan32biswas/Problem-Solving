#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("Input.txt", "r", stdin);
    int num, pos, arr[1000], Max, ans, n, i, J;
    bool ck;
    while(cin>>n){
        ck = true;
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);
            if(ck && arr[i]){
                num=arr[i];
                ck = false;
            }
        }
        for(i=0, pos=0, ans=0; i<n; i=pos){
            for(J=i, Max=0; J<n; J++, Max++){
                if(arr[J]!=0 && arr[J]!=num){
                    num = arr[J];
                    break;
                }
                if(arr[J]==num){
                    pos = J+1;
                }
            }
            if(Max>ans) ans = Max;
            if(J==n) break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
