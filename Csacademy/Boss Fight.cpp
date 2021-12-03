#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL X, Y;
LL A1, L1, A2, L2;
bool Check(int a, int l) {
    LL incA = X*a + A1;
    LL incL = Y*l + L1;
    LL you = L2/incA;
    LL boss = incL/A2;
    return you<boss || (you==boss && L2%incA<incL%A2);
}
bool solve() {
    int C;
    cin>>A1>>L1>>A2>>L2;
    cin>>C>>X>>Y;
    for(int i=0; i<=C; i++){
        if(Check(i, C-i)){
            return true;
        }
    }
    return false;
}
int main() {
    cout<<solve()<<endl;
}
