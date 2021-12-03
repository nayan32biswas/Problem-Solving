#include <bits/stdc++.h>
using namespace std;
#define Size 200009
int arr[Size], temp, ans;
long long sum;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)scanf("%d", &arr[i]), sum+=arr[i];
    sum = (sum+1)/2;
    for(int i=0; i<n; i++){
        temp+=arr[i];
        if(temp>=sum){
            ans = i;
            break;
        }
        ans = i;
    }
    printf("%d\n", ++ans);
    return 0;
}
