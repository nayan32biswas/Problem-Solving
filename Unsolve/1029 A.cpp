#include <bits/stdc++.h>
using namespace std;
bool isSame(string str, int pos){
    int i, len=str.size();
    for(i=0; pos<len && str[i]==str[pos]; i++, pos++);
    if(pos==len) return true;
    return false;
}
string cut(string str) {
    string temp="";
    int len = str.size();
    for(int i=(len+1)/2; i<len; i++){
        if(isSame(str, i)){
            i = len-i;
            for(; i<len; i++){
                temp += str[i];
            }
            break;
        }
    }
    len = temp.size();
    int i;
    if(len==0) temp = str, len = str.size();
    for(i=0; i<len && temp[0]==temp[i]; i++);
    if(i==len){
        temp = "";
        temp += str[0];
    }
    return temp;
}
int main() {
    int n, k;
    string str, temp="";
    cin>>n>>k>>str;
    temp = str;
    string inc = cut(str);

    //cout<<inc<<endl;

    k--;
    while(k--) {
        temp += inc;
    }
    cout<<temp<<endl;
    return 0;
}
/**
1 50
aaabbbbccccaa
*/



