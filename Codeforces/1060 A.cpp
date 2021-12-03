#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int eight=0, n;
    cin>>n>>str;
    for(auto it : str)if(it=='8')eight++;
    cout<<min(n/11, eight)<<endl;
    return 0;
}
