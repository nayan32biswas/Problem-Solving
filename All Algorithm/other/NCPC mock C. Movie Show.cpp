#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test, D, N, R;
    string str;
    cin>>test;
    map<string, int>M;
    for(int t=1; t<=test; t++){
        cin>>D>>N;
        while(N--){
            cin>>str>>str>>R;
            if(M[str]==0)M[str] = INT_MAX;
            M[str] = min(M[str], R);
        }
        int coun = 0;
        for(auto it : M){
            coun += it.second;
        }
        printf("Case %d: ", t);
        if(coun<=D){
            cout<<D<<endl;
        }
        else{
            puts("Movie show canceled!");
        }
    }
    return 0;
}
