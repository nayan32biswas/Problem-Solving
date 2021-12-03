#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M, x;
    while(scanf("%d%d", &N, &M) && N && M){
        set<int>A;
        for(int i=0; i<N; i++) {
            scanf("%d", &x);
            A.insert(x);
        }
        for(int i=0; i<N; i++) {
            scanf("%d", &x);
            A.insert(x);
        }
        printf("%d\n", (N+M)-A.size());
    }
    return 0;
}
