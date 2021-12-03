#include <bits/stdc++.h>
using namespace std;
int comp(string a, string b){
    int coun = 0;
    if(b.size()==0 || a.size()==0) return 10;
    for(int i=0; i<a.size(); i++)
        if(a[i]!=b[i]) coun++;
    return coun;
}
int Find(vector<string>&aaa, vector<string>&bbb){
    int ans = 0, temp, pos;
    for(auto itb : bbb){
        int Min = 10, i=0;
        for(auto ita : aaa){
            temp = comp(ita, itb);
            if(temp<=Min){
                pos = i;
                Min = temp;
            }
            i++;
        }
        aaa[pos] = "";
        ans += Min;
    }
    return ans;
}
void Copy(vector<string>A, vector<string>&B){
    B.clear();
    for(auto it : A)B.push_back(it);
}
int main()
{
    vector<string>A[4], B[4], X, Y;
    int n, ans=0;
    string str;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>str;
        if(str.size()>4) continue;
        A[str.size()-1].push_back(str);
    }
    for(int i=0; i<n; i++){
        cin>>str;
        B[str.size()-1].push_back(str);
    }
    for(int i=0; i<4; i++){
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
    }
    for(int i=0; i<4; i++)if(A[i].size()){
        Copy(A[i], X);
        Copy(B[i], Y);
        reverse(X.begin(), X.end());
        reverse(Y.begin(), Y.end());
        ans += min(Find(A[i], B[i]), Find(X, Y));
    }
    cout<<ans<<endl;
    return 0;
}
