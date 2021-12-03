#include <bits/stdc++.h>
using namespace std;
unsigned long long arr[100009];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, k, i, j, l, x=0, start=clock();
    cin>>n>>k;
    for(i=0; i<n; i++) scanf("%llu", &arr[i]);

    sort(arr, arr+n);
    reverse(arr, arr+n);

    unsigned long long ans, Max, Max1=1, temp;
    temp = arr[k-1], i=2;
    while(i<temp){
        i<<=1;
    }
    if(i>temp) i>>=1;
    temp = i+1;
    for(i=k; i<n; i++) if(arr[i]<temp){n = i; break;}

    for(i=1, Max = arr[0]; i<k; i++) Max&=arr[i];

    for(j=k; j<n; j++)if((Max&arr[j])>=Max){
        if(clock()-start>1900) break;
        for(l=0; l<k; l++){
            temp = arr[l]&Max;
            if(temp>Max){
                swap(arr[j], arr[l]);
                for(i=1, ans = arr[0]; i<k; i++) ans&=arr[i];
                //for(i=0; i<k; i++) cout<<arr[i]<<' ';cout<<endl;
                if(ans==Max) Max1++;
                else if(ans>Max) Max=ans, Max1=1;
                break;
            }
            else if(temp==Max) Max1++;
        }

    }

    cout<<(Max%1000000007)<<endl<<Max1<<endl;
    return 0;
}
