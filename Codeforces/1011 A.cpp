#include <bits/stdc++.h>
using namespace std;
string str;
void Unique() {
    string temp = "";
    map<char, bool>M;
    for(auto it : str)
        if(M[it]==0)
            temp += it, M[it] = 1;
    str = temp;
}
int main() {
    int n, k;
    cin>>n>>k>>str;
    Unique();
    n = str.size();
    sort(str.begin(), str.end());
    string anss = "";
    int ans = 0;
    for(auto it : str) {
        if(anss.size()) {
            if(anss[anss.size()-1]<it-1)
                anss += it, k--;
        } else
            anss += it, k--;
        if(k==0)
            break;
    }
    if(k>0)
        return puts("-1"), 0;
    for(auto it : anss)
        ans += int(it-'a')+1;
    cout<<ans<<endl;
    return 0;
}
