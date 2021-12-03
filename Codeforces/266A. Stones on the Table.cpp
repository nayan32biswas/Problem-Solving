#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, cou=0;
    cin>>n>>s;
    for(int i=0; i<n; i++){
        if(s[i]==s[i+1]) cou++;
    }
    cout<<cou<<endl;
    return 0;
}
