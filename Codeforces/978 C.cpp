#include <bits/stdc++.h>
using namespace std;
#define Size 200005
long long dormitory[Size], roomNumber[Size];

int main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i=0; i<n; i++)
        cin>>dormitory[i];
    for(int i=0; i<m; i++)
        cin>>roomNumber[i];

    long long total=0, pass=0;
    int i, j;
    for(i=0, j=0; i<n && j<m; ) {
        if((total+dormitory[i])>=roomNumber[j]) {
            printf("%d %lld\n", i+1, roomNumber[j]-total);
            j++;
        } else {
            total+=dormitory[i];
            i++;
        }
    }
    for(; j<m; j++) {
        printf("%d %lld\n", n, total-roomNumber[j]);
    }
    return 0;
}

