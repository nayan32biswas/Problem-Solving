#include <bits/stdc++.h>
using namespace std;
int arr[100];
int find(int a, int b){
    if(a>b)swap(a, b);
    if(a==1 && b==3)return 4;
    if(a==1 && b==2) return 3;
    return 0;
}
int main()
{
    int n, ans=0, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<n; i++){
        x = find(arr[i], arr[i-1]);
        if(!x) return 0*puts("Infinite");
        ans+=x;
    }
    for(int i=2; i<n; i++){
        if(arr[i]==2 && arr[i-1]==1 && arr[i-2]==3) ans--;
    }
    puts("Finite");
    cout<<ans<<endl;
    return 0;
}