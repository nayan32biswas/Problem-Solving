#include <bits/stdc++.h>
using namespace std;
int arr[2005], brr[2005];
int main()
{
    int n, coun=0;
    map<int, bool>ma;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i], ma[arr[i]];
    for(int i=0; i<n; i++) cin>>brr[i], ma[arr[i]];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ma[(arr[i]^brr[i])]) coun++;
        }
    }

    puts(coun&1 ? "Koyomi" : "Karen");
    return 0;
}
