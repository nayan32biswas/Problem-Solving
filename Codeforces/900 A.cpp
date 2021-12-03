#include <bits/stdc++.h>
using namespace std;
#define Size 1000
map<int, bool>X, Y;
int main()
{
    int n, valid=0, x, y;
    cin>>n;
    for(int i=0; i<n; i++){
        scanf("%d%d", &x, &y);
        if(X[x]) valid++;
        if(Y[y]) valid++;
        if(valid>1) return puts("No"), 0;
        X[x] = 1;
        Y[y] = 1;
    }
    puts("Yes");
    return 0;
}
