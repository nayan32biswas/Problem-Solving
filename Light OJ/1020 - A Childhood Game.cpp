#include <bits/stdc++.h>
using namespace std;
int main() {
    int test, n;
    char str[5];
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%d%s", &n, str);
        printf("Case %d: ", t);
        n %= 3;
        if(str[0]=='A') {
            if(n==2 || n==0) {
                puts("Alice");
            } else {
                puts("Bob");
            }

        } else {
            if(n==3 || n==0) {
                puts("Alice");
            } else {
                puts("Bob");
            }
        }
    }
    return 0;
}
