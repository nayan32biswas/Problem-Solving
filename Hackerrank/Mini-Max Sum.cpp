#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long arr[10], Min=0, Max=0;
    for(int i=0; i<5; i++)
        cin>>arr[i];
    sort(arr,arr+5);
    for(int i=0; i<5; i++){
        if(i!=0)
            Max+=arr[i];
        if(i!=4)
            Min+=arr[i];
    }
    cout<<Min<<' '<<Max<<endl;
    return 0;
}
