#include <bits/stdc++.h>
using namespace std;
bool palin(int h, int m){
    string s="";
    char c;
    if(h<10){
        s+="0";
        if(h==0) s+="0";
        else{c = h+48; s+=c;}
    }
    else{
        c=(h%10)+48; h/=10;
        s+=(char)(h+48);
        s+=c;
    }
    if(m<10){
        s+="0";
        if(m==0) s+="0";
        else{c = m+48; s+=c;}
    }
    else{
        c=(m%10)+48; m/=10;
        s+=(char)(m+48);
        s+=c;
    }
    int i, j;
    for(i=0, j=3; i<j; i++, j--)if(s[i]!=s[j])return false;
    return true;
}
int main()
{
    string s;
    int ans=0, h, m;
    cin>>s;
    h=(s[0]-48)*10; h+=(s[1]-48);
    m=(s[3]-48)*10; m+=(s[4]-48);
    while(!palin(h, m)){
        //if(h==23 && m==60) break;
        m++;
        ans++;
        if(m==60){
            h++, m=0;
            if(h>23) h=0;
        }
    }
    cout<<ans<<endl;

}
