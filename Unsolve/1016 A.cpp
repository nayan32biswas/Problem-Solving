#include <bits/stdc++.h>
using namespace std;
#define Size 100001
int arr[Size];
int main()
{
    int n, m;
    long long remain = 0;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    long long temp, ans;
    for(int i=0; i<n; i++){
        remain += arr[i];
        temp = remain%m;
        ans = 0;
        if(temp==0){
            ans = 1;
        }
        cout<<(ans+(remain/m))<<" ";
        remain = m-temp;
        cout<<remain<<endl;
    }
    return 0;
}
