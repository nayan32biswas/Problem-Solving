#include <bits/stdc++.h>
using namespace std;
bool check;
int to_int(string str){
    int n = 0;
    if(str[0]=='0') return 3;
    for(auto it : str)
        n = ((n*10)+(it-'0'));
    return n;
}
bool is_parfect(int n){
    int x = sqrt(n);
    if(x*x==n) return true;
    x++;
    if(x*x==n) return true;
    return false;
}
void combination(string str, char temp[], int start, int End, int index, int r) {
    if(index == r) {
        string s="";
        for(int i=0; i<r; i++)
            s += temp[i];
        if(is_parfect(to_int(s)))check = true;
        return;
    }
    for(int i=start; i<=End && (r-index)<=(End-i+1); i++) {
        if(check) return;
        temp[index] = str[i];
        combination(str, temp, i+1, End, index+1, r);
    }
}

int main() {
    string str;
    cin>>str;
    int len = str.size(), ans;
    char temp[len];
    //for(int i=0; i<len; i++) str[i] -= 48;
    for(int i=len; i>0; i--){
        combination(str, temp, 0, len-1, 0, i);
        if(check){
            return printf("%d\n", len-i), 0;
        }
    }
    puts("-1");
    return 0;
}
