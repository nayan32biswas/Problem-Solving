#include <bits/stdc++.h>
using namespace std;
map<char, bool>mark;
int main()
{
    freopen("input.txt", "r", stdin);
    int n, i, len;
    string arr[105], ans="", s="", first;
    cin>>n;
    cin>>first;
    len = first.size();
    mark[first[0]]=true;
    s += first[0];

    for(i=0, n--; i<n; i++){
        cin>>arr[i];
        if(!mark[arr[i][0]]){
            s+=arr[i][0];
            mark[arr[i][0]]=true;
        }
        if(arr[i].size()<len)return puts("Impossible"), 0;
    }
    cout<<s<<endl;

    return 0;
}
