#include <bits/stdc++.h>
using namespace std;
map<string, int>M;
int len, hi;
string exchang(string s) {
    char temp=s[0];
    for(int i=0; i<len-1; i++){
        s[i]=s[i+1];
    }
    s.erase(hi);
    s+=temp;
    return s;
}
int main()
{
    string s[60], temp;
    int n, i, j, k, ans, mainans;
    cin>>n;
    if(n==1)return puts("0"), 0;
    cin>>s[0];
    len = s[0].size();
    hi = len-1;
    for(i=1; i<n; i++){
        cin>>s[i];
        if(len!=s[i].size()){
            return puts("-1"), 0;
        }
    }

    for(i=0, mainans=99999999; i<n; i++){
        for(j=0, ans=0; j<n; j++)if(i!=j){
            temp = s[j], k=0;
            while(temp!=s[i]){
                temp = exchang(temp);
                k++;
                if(k>=len){
                    return puts("-1"), 0;
                }
            }
            ans+=k;
        }
        mainans=min(ans, mainans);
    }
    cout<<mainans<<endl;
    return 0;
}
