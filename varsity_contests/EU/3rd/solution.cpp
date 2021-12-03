#include <bits/stdc++.h>
using namespace std;
bool Find(string text, string pattern){
    int len1 = text.size(), len2 = pattern.size();
    for(int i=0, j; i<len1; i++){
        for(j=0; j<len2; j++){
            if(text[i+j]!=pattern[j])
                break;
        }
        if(j==len2)
            return true;
    }
    return false;
}
int main()
{
    // freopen("input4.txt", "r", stdin);
    // freopen("output4.txt", "w", stdout);
    string a, b;
    getline(cin, a);
    cin>>b;
    // cout<<a<<","<<b<<endl;
    if(Find(a, b)){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}