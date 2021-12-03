#include <bits/stdc++.h>
using namespace std;
string reformate(string &str){
    string temp = "";
    for(auto it : str){
        if(it=='=') temp+=" ";
        else if(isdigit(it)){
            temp += it;
        }
        else {
            temp+=" ";
            temp+=it;
        }
    }
    //cout<<temp<<endl;
    return temp;
}
bool solve(string &str) {
    str = reformate(str);
    string temp="";
    stringstream ss;
    ss << str;
    int number, num=0, i=0;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> number) {
            //cout<<number<<" ";
            if(i<2)num+=number;
            else if(i==2){
                //cout<<num<<" "<<number<<endl;
                return num==number ? true : false;
            }
            i++;
        }
        temp = "";
    }
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int coun = 0;
    string str;

    while(cin>>str){
        if(solve(str))coun++;
    }
    cout<<coun<<endl;
    return 0;
}
