#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    set<string>Set;
    int test, N;
    cin>>test;
    while(test--){
        cin>>N;
        //Set.clear();
        string A, B;
        while(N--){
            cin>>A>>B;
            Set.insert(A);
            Set.insert(B);
            printf("%d\n", Set.size());
        }
    }
    return 0;
}
