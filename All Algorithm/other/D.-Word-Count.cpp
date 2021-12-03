#include <bits/stdc++.h>
using namespace std;
map<string,int>m;
int main()
{
    //freopen("Input.txt", "r", stdin);
    int len, sum, i, j, Max=0, top=0, top1=0;
    string s, temp, cpy;
    while(getline(cin, s)){
        len=s.size();
        temp="";
        for(i=0, j=0; i<len; i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                m[temp]++;
                if(m[temp]>Max){
                    Max=m[temp];
                    cpy=temp;
                    top1++;
                }
                j=0;
                temp="";
            }
        }
        m[temp]++;
        if(m[temp]>Max){
            Max=m[temp];
            cpy=temp;
            top1++;
        }
        if(len>=20 || top1>=100) break;
    }
    cout<<cpy<<endl;
    return 0;
}
