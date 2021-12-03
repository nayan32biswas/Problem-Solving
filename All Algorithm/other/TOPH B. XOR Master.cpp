#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[101000], n;
int main()
{
    int i, J, k, num1=-1, temp=0;
    long long ans=0;
    cin>>n;
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr+n);
    for(i=0; i<n; i++){
        if(num1==arr[i] && i){
            ans+=temp;
            continue;
        }num1=arr[i];
        for(J=i, temp=0; J<n; J++){
            if((arr[i]^arr[J])>0){
                temp=n-J;
                break;
            }
        }
        ans+=temp;
    }
    cout<<ans<<endl;
    return 0;
}
