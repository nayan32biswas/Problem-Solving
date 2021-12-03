#include <bits/stdc++.h>
using namespace std;
long long arr[10000000];
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, text = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    char c;
    cin>>c>>s;
    int i, j, Len, len;
    Len = text.size();
    if(c=='L'){
        for(i=0, len=s.size(); i<len; i++){
            c = s[i];
            for(j=0; j<Len; j++)if(text[j]==c)break;
            cout<<text[++j];
        }
    }
    else {
        for(i=0, len=s.size(); i<len; i++){
            c = s[i];
            for(j=0; j<Len; j++)if(text[j]==c)break;
            cout<<text[--j];
        }
    }
    cout<<endl;
    return 0;
}
