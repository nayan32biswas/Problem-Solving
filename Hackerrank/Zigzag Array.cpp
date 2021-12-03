#include <bits/stdc++.h>
using namespace std;
int arr[110], n;
void erose(int i) {
    for(; i<n; i++)arr[i]=arr[i+1];
}
int main()
{
    int i, ans=0;
    cin>>n;
    for(i=0; i<n; i++) scanf("%d", &arr[i]);
    for(i=0; i<n-2; i++){
        if(arr[i]<arr[i+1] && arr[i+1]<arr[i+2]){
            n--, ans++;
            erose(i); i--;
        }
        else if(arr[i]>arr[i+1] && arr[i+1]>arr[i+2]){
            n--, ans++;
            erose(i); i--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/// 1 5 9 2 4 7 8 5 2 3
