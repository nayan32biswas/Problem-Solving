#include <bits/stdc++.h>
using namespace std;
string s="Blbasur";
char String[100050], c;
int arr[130];
int main()
{
    cin>>String;
    int i, J, ans=99999999, len;
    len = strlen(String);
    for(i=0; i<len; i++) arr[String[i]]++;
    for(i=0; i<7; i++){
        J = arr[s[i]];
        if(s[i]=='a' || s[i]=='u'){
            J/=2;
        }
        ans = min(ans, J);
    }
    cout<<ans<<endl;
    return 0;
}
/// Bulbasaur
