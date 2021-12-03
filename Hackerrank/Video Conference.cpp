#include <bits/stdc++.h>
using namespace std;
map< string, int >data, allData;
void make(string str){
    if(data[str]>0){
        data[str]++;
        cout<<str<<" "<<data[str]<<endl;
        return;
    }
    data[str]= 1;
    bool check = true;
    string temp = "";
    for(auto it : str){
        temp += it;
        if(check && allData[temp]==0){
            cout<<temp<<endl;
            check = false;
        }
        allData[temp]++;
    }
    if(check) cout<<str<<endl;
}
int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    string str;
    scanf("%d", &n);
    while(n--){
        cin>>str;
        make(str);
    }
    return 0;
}
