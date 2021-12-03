#include <bits/stdc++.h>
using namespace std;
int arr[130];
int main()
{
    arr['a']=1, arr['e']=1, arr['i']=1;
    arr['o']=1, arr['u']=1, arr['y']=1;
    string s;
    cin>>s;
    for(int i=1; s[i]; i++) {
        if(s[i]==s[i-1] || (arr[s[i]] && arr[s[i-1]])){
            return puts("No"), 0;
        }
    }
    return puts("Yes"), 0;
}
