#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int i, n;
string s;
void call(){
    int num=0;
    while(i<n && s[i]=='1')num++, i++;
    ans.push_back(num);
    i--;
}
int main()
{
    cin>>n>>s;
    for(i=0; i<n; i++){
        if(s[i]=='0'){
            bool ck=false;
            while(i<n && s[i]=='0'){
                if(ck)ans.push_back(0);
                ck=!ck;
                i++;
            }
        }
        if(i<n) call();
    }
    for(auto T:ans)cout<<T;
    cout<<endl;
    return 0;
}
