#include <bits/stdc++.h>
using namespace std;
#define Size 5005
int arr[Size];
int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    for(int i=1; i<=n; i++) {
        if(arr[arr[arr[arr[i]]]]==arr[i])
            return puts("Yes"), 0;
    }
    puts("No");

    return 0;
}
