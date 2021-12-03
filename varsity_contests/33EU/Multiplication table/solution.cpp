#include <bits/stdc++.h>
using namespace std;
string solve()
{
    int N;
    cin>>N;
    int last = 1;
    for(int i=2; i*i<=N; i++){
        if(N%i==0){
            last = i;
        }
    }
    N = N/last;
    if(N>10 || last>10)return "No";
    return "Yes";
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int test;
    cin>>test;
    for(int t=1; t<=test; t++){
        cout << solve() << endl;
    }
}