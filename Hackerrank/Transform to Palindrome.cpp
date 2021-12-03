#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-') {
        c=getchar();
        t=true;
    }
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}
int check[100009], arr[100009], L[10009][10009];
int Find(int r) {
    if(check[r]==r) return r;
    else check[r] = Find(check[r]);
    return check[r];
}

int lps(int str[], int n) {
    int i, j, cl;
    for (i = 0; i < n; i++) L[i][i] = 1;
    for(cl=2; cl<=n; cl++) {
        for(i=0; i<n-cl+1; i++) {
            j = i+cl-1;
            if(str[i]==str[j] && cl == 2)
                L[i][j] = 2;
            else if(str[i] == str[j])
                L[i][j] = L[i+1][j-1] + 2;
            else
                L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
    return L[0][n-1];
}
int main() {
    //freopen("input.txt", "r", stdin);
    int i, j, n, k, m, x, y, lo, hi, ans;
    scanf("%d%d%d", &n, &k, &m);
    for(i=0; i<=n+5; i++)check[i]=i;
    for(i=0; i<k; i++) {
        read(x);
        read(y);
        x = Find(x);
        y = Find(y);

        if(x!=y) {
            check[x]=y;
        }
    }
    for(i=0; i<m; i++) {
        read(x);
        arr[i]=Find(x);
    }
    //for(i=0; i<m; i++) printf("%3d", arr[i]);puts("");
    printf("%d\n", lps(arr, m));
    return 0;
}
