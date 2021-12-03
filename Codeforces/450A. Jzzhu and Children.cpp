#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int arr[111], n, m, x, ans=0;
    bool ck;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    while(1){
        ck=false;
        for(int i=0; i<n; i++){
            if(arr[i]>0){
                ck=true;
                ans=i+1;
            }
            arr[i]=arr[i]-m;
        }
        if(ck==false) break;
    }
    cout<<ans<<endl;
    return 0;
}
