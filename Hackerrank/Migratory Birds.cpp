#include <bits/stdc++.h>
#define SIZ 200050
using namespace std;
int arr[SIZ];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, Max=0, value;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d", &value);
        arr[value]++;
        if(value>Max) Max = value;
    }value = 0;
    for(int i=0; i<=Max; i++){
        if(arr[i]>value) value = i;
    }
    cout<<value<<endl;
    return 0;
}
