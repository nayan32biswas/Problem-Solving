#include <bits/stdc++.h>
using namespace std;
struct data
{
    string s;
    int line;
}value[120010];

vector<string>ans;
map<string, bool>M;
int arr[1300];
void finde();

int main()
{
    //freopen("input.txt", "r", stdin);
    string s1, s2;
    int pos=0, i, J, len, len1, len2;
    while(cin>>value[pos].s){
        if(value[pos].s[0]==0) break;
        i = value[pos].s[0];
        len = value[pos].s.size();
        arr[len]=1;
        value[pos].line = len;
        M[value[pos].s]=1;
        pos++;
    }
    for(i=0; i<pos; i++){
        s1.clear();
        s1 = value[i].s;
        len = value[i].line;
        if(len>0){
            for(J=0; J<pos; J++){
                if(arr[value[J].line+len]>0){
                    s2.clear();
                    s2 = s1+value[J].s;
                    if(M[s2]==1){
                        ans.push_back(s2);
                        break;
                    }
                }
            }
        }
    }
    len = ans.size();
    sort(ans.begin(), ans.end());
    for(i=0; i<len; i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
