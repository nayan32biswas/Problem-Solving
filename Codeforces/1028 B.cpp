#include <bits/stdc++.h>
using namespace std;
void Add(string &str, string &strB, int len){
    len = min((2000/2), len);
    for(int i=0; i<len; i++){
        if(i==len-1){
            str += "19";
            strB += "81";
        }
        else{
            str += "18", strB+="81";
        }
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    posN = n-1;
    string a = "", b="";
    Add(a, b, n);
    cout<<a<<"\n"<<b<<endl;
    return 0;
}
