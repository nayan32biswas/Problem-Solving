#include <bits/stdc++.h>
using namespace std;
#define Size 144
string strArray[Size];
bool cmp(string a, string b){
    int len = a.size();
    int len1 = b.size();
    if(len == len1)return a<b;
    return len<len1;
}
bool Check(string str, int len);
int main()
{
    freopen("input.txt", "r", stdin);
    int N;
    cin>>N;
    cin.ignore();
    cin.ignore();
    for(int t=0; t<N; t++){
        if(t) puts("");
        int len=0;
        while(getline(cin, strArray[len]) && strArray[len].size()>0)
            len++;
        sort(strArray , strArray + len, cmp);
        bool found = true;
        for(int i=0; i<len && found; i++){
            for(int j=0; j<i; j++){
                if(Check(strArray[i]+strArray[j], len)){
                    cout<<strArray[i]+strArray[j]<<endl;
                    found = false;
                    break;
                }
                if(Check(strArray[j]+strArray[i], len)){
                    cout<<strArray[j]+strArray[i]<<endl;
                    found = false;
                    break;
                }
            }
        }

    }
}
bool Check(string str, int len){
    for(int i=0; i<len; i++){
        if(str.find(strArray[i])>INT_MAX) return false;
    }
    return true;
}
