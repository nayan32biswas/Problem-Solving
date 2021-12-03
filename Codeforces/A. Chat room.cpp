#include <iostream>
using namespace std;
int main()
{
    string s1="hello", s;
    cin>>s;
    int i, J;
    for(i=0, J=0; s[i] && J<5; i++){
        if(s[i]==s1[J])J++;
    }
    if(J==5)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
