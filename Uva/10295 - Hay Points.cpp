#include <bits/stdc++.h>
using namespace std;
long long Find(map<string, int>&M, string str){
    string temp = "";
    long long ans=0;
    for(auto it : str){
        if(it==' '){
            ans += M[temp];
            temp = "";
        }
        else
            temp += it;
    }
    return ans+M[temp];
}
int main()
{
    string str;
    map<string, int>M;
    int m, n, value;
    scanf("%d%d", &m, &n);
    for(int i=0; i<m; i++){
        cin>>str>>value;
        M[str] = value;
    }
    while(n--){
        long long ans = 0;
        while(getline(cin, str) && str!="."){
            ans += Find(M, str);
        }
        cout<<ans<<endl;
    }
    return 0;
}
