#include <bits/stdc++.h>
using namespace std;
int to_int(string s){
    int num=0, len=s.size();
    for(int i=0; i<len; i++){num=(num*10)+(s[i]-'0');}
    return num;
}
int main()
{
    int len, i, num, num1;
    string s;
    cin>>s;
    len = s.size();
    if(len==1){return puts("1"), 0;}
    num = to_int(s);
    if(s[0]=='9'){s.clear();s+="10";}
    else {char c=s[0]+1; s.clear(); s+=c;}
    for(i=1; i<len; s+='0', i++);
    cout<<(to_int(s)-num)<<endl;
}
