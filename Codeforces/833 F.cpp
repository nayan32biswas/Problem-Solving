#include<bits/stdc++.h>
using namespace std;
int main() {

    int n, len;
    cin>>n;
    string str, s;
    set<string>SET;
    bool ck;
    for(int i=0; i<n; i++) {
        cin>>str;
        s = "";
        ck = false;
        len = str.size();
        for(int j=len-1; j>=0; j--){
            if(ck && str[j]=='k')continue;
            else if(j>0 && str[j]=='h' && str[j-1]=='k'){
                ck = true;
                j--;
                s+='h';
            }
            else {
                ck = false;
                s+=str[j];
            }

        }
        reverse(s.begin(), s.end());
        str.clear();
        for(auto c : s)c=='u' ? str+="oo" : str+=c;
        s.clear();
        len = str.size();
        for(int j=0; j<len; j++){
            if(j<(len-1) && str[j]=='o' && str[j+1]=='o') {
                s+='u';
                j++;
            }
            else s+=str[j];
        }
        SET.insert(s);

    }
    cout<<SET.size()<<endl;
}






/*
#include <bits/stdc++.h>
using namespace std;
#define Size 500
vector<string> arr[Size];
string oo_to_u(string s){
    string t = "";
    int len = s.size();
    for(int i=0; i<len; i++){
        if(i<(len-1) && s[i]=='o' && s[i+1]=='o') {
            t+='u';
            i++;
        }
        else t+=s[i];
    }
    return t;
}
string oo_to_u_back(string s){
    string t = "";
    int len = s.size();
    for(int i=len-1; i>=0; i--){
        if(i!=0 && s[i]=='o' && s[i-1]=='o') {
            t+='u';
            i--;
        }
        else t+=s[i];
    }
    reverse(t.begin(), t.end());
    return t;
}

string kh_to_h(string s){
    string t = "";
    int len = s.size();
    for(int i=0; i<len; i++){
        if(i<(len-1) && s[i]=='k' && s[i+1]=='h') {
            t+='h';
            i++;
        }
        else t+=s[i];
    }
    return t;
}

string kh_to_h_back(string s){
    string t = "";
    int len = s.size();
    for(int i=len-1; i>=0; i--){
        if(i!=0 && s[i]=='h' && s[i-1]=='k') {
            t+='h';
            i--;
        }
        else t+=s[i];

    }
    reverse(t.begin(), t.end());
    return t;
}

void to_u1(string s, int i){
    string s1 = oo_to_u(s);
    if(s1!=s){
        arr[i].push_back(s1);
        to_u1(s1, i);
    }
    s1 = oo_to_u_back(s);
    if(s1!=s){
        arr[i].push_back(s1);
        to_u1(s1, i);
    }
}

void to_h(string s, int i){
    string s1 = kh_to_h(s);
    if(s1!=s){
        arr[i].push_back(s1);
        to_h(s1, i);
        to_u1(s1, i);
    }
    s1 = kh_to_h_back(s);
    if(s1!=s){
        arr[i].push_back(s1);
        to_h(s1, i);
        to_u1(s1, i);
    }
}
void to_u(string s, int i){
    string s1 = oo_to_u(s);
    if(s1!=s){
        arr[i].push_back(s1);
        to_u(s1, i);
        to_h(s1, i);
    }
    s1 = oo_to_u_back(s);
    if(s1!=s){
        arr[i].push_back(s1);
        to_u(s1, i);
        to_h(s1, i);
    }
}

void print(int n){
    for(int i=0; i<n; i++){
        for(auto a : arr[i]) cout<<a<<" ";puts("");
    }
    puts("");
}

int mark[Size];
int Find(int r){
    if(mark[r]==r) return r;
    return mark[r] = Find(mark[r]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin>>n;
    string s;
    for(int i=0; i<n; i++) mark[i] = i;
    for(int i=0; i<n; i++){
        cin>>s;
        arr[i].push_back(s);
        if(s.size()<=1) continue;
        to_h(s, i);
        to_u(s, i);
    }

    for(int i=0; i<n; i++){
        x = Find(i);
        for(auto a : arr[i]){
            for(int j=i+1; j<n; j++){
                for(auto b : arr[j]){
                    if(a==b){
                        y = Find(j);
                        if(x!=y)mark[y] = x;
                        break;
                    }
                }
            }
        }
    }
    //print(n);
    set<int>SSS;
    for(int i=0; i<n; i++)SSS.insert(Find(i));
    //for(auto a : SSS) cout<<a<<" "; puts("");
    cout<<SSS.size()<<endl;
    return 0;
}
*/
