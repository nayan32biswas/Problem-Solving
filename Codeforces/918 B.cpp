#include <bits/stdc++.h>
using namespace std;
map<string, string> Map;
int main()
{
    int n, m;
    string str, str1;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>str>>str1;
        str1+=';';
        Map[str1] = str;
    }
    for(int i=0; i<m; i++){
        cin>>str>>str1;
        cout<<str<<" "<<str1<<" #"<<Map[str1]<<endl;
    }
    return 0;
}

