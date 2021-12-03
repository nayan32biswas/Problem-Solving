#include <bits/stdc++.h>
using namespace std;
#define Size 1005
int arr[Size];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(!(arr[i]&1)){
            arr[i]--;
        }
    }
    for(int i=0; i<n; i++){
        if(i) printf(" ");
        cout<<arr[i];
    }
    puts("");
    return 0;
}
