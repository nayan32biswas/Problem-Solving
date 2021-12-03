#include <iostream>
#include <cstdio>
using namespace std;
int arr[109], n, ans, temp;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    bool ck=true;
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        if(ck) {
            if(temp>arr[i]){
                ans++; ck=false;
            }
        }
        else {
            if(arr[i]>temp){
                ans++; ck=true;
            }
        }
    }
    if(!ans)return puts("-1"), 0;
    else printf("%d\n", ans);
    return 0;
}
