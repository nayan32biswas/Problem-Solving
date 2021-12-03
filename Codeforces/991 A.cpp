#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, N;
    cin>>A>>B>>C>>N;
    if(A<C || B<C)
        return puts("-1"), 0;
    A -= C;
    B -= C;
    if((N-(A+B+C))<1)
        return puts("-1"), 0;
    cout<<N-(A+B+C)<<endl;
    return 0;
}
