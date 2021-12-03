#include <bits/stdc++.h>
using namespace std;
int n, z;
vector<pair<int, int>>node;
int lower(int key){
    int start=0, End = n-1, mid;
    while(start<=End){
        mid = (start+End)/2;
        if(node[mid].first<key)start=mid+1;
        else End = mid-1;
    }
    mid = max(0, mid-5);
    while(node[mid].first<key && mid<n)mid++;
    while(!node[mid].second && mid<n)mid++;
    // cout<<mid<<" "<<node[mid].first<<" "<<node[mid].second<<endl;
    if(mid<n && node[mid].second && node[mid].first>=key){
        node[mid].second--;
        return true;
    }
    return false;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int a;
    map<int, int>coun;
    scanf("%d%d", &n, &z);
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        coun[a]++;
    }
    for(auto it : coun){
        node.push_back(make_pair(it.first, it.second));
    }
    n = node.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        // cout<<i<<endl;
        while(node[i].second>0){
            node[i].second--;
            if(lower(node[i].first+z))ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}