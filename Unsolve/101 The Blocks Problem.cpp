#include <bits/stdc++.h>
using namespace std;
vector<string>String;
bool make(string str){
    String.clear();
    string temp="";
    for(auto it : str){
        if(it==' '){
            String.push_back(temp);
            temp = "";
        }
        else temp+=it;
    }
    if(temp=="quit") return false;
    String.push_back(temp);
    return true;
}
int to_int(string str){
    int n=0;
    for(auto it : str)
        n = (n*10)+(it-'0');
    return n;
}
int main()
{
    int n, a, b;
    string str;
    while(cin>>n){
        cin.ignore();
        while(getline(cin, str)){
            if(!make(str)) break;
            a = to_int(String[1]);
            b = to_int(String[3]);
            cout<<a<<" "<<b<<endl;
        }
    }
    return 0;
}
