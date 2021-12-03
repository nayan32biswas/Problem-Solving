#include <iostream>
using namespace std;
int main()
{
    string s;
    int n, a, b, len, cou=0;
    bool ck;
    cin>>n>>a>>b>>s;
    if(s[a-1]==s[b-1]){
        cout<<'0'<<endl;
    }
    else{
        cout<<'1'<<endl;
    }
    return 0;
}
