#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int arr[1000009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i, J, m, q;
    cin>>n;
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    cin>>q;
    for(i=0; i<q; i++) {
        scanf("%d", &m);
        if(m>100000) J=n;
        else for(J=0; arr[J]<=m && J<n; J++);
        cout<<J<<endl;
    }
    return 0;
}
