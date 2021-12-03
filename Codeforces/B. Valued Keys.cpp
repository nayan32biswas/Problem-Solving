#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int len, i;
    string s, s1;
    cin>>s>>s1;
    len = s.size();
    for(i=0; i<len; i++) {
        if(s[i]<s1[i]) return puts("-1"), 0;
    }
    cout<<s1<<endl;
    return 0;
}
