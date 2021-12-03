#include <bits/stdc++.h>
using namespace std;
template <typename T>
void input(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}
#define Size 1000009
bool A[Size], B[Size], ck, ck1;
int Max, x, y;
void check_gcd(vector<int>a, vector<int>b){
    int G;
    for(auto X:a)for(auto Y:b){
        G = __gcd(X, Y);
        if(G>Max)Max = G, x = X, y = Y;
        else if(G==Max && (X+Y)>(x+y))x = X, y = Y;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, n, num, M=0;
    Max = 0;
    input(n);
    for(i=0; i<n; i++) {
        input(num);
        A[num]=1;
        M = max(M, num);
    }
    for(i=0; i<n; i++) {
        input(num);
        B[num]=1;
        M = max(M, num);
    }
    M+=5;
    vector<int>a, b;
    for(i=2; i<M; i++){
        num=i;
        a.clear();
        b.clear();
        for(j=2; num<M; j++){
            if(A[num]) a.push_back(num);
            if(B[num]) b.push_back(num);
            num *= j;
        }
        check_gcd(a, b);
    }
    cout<<(x+y)<<endl;
    return 0;
}
