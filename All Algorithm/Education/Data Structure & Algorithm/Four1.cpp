#include <bits/stdc++.h>
using namespace std;
int arr[1000], N;
int main()
{
    scnf("%d", &N);
    int sum = 0, i;
    for(i=0; i<N; i++) scnf("%d", &arr[i]);
    for(i=0; i<N; i++)if(arr[i]%2==0) sum+=arr[i];
    if(sum<50) puts("True");
    else puts("False");
}
