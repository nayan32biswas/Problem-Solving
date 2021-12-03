#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int main()
{
    int n;
    string str;
    cin>>n;
    map<string, string>Map;
    Map["purple"] = "Power";
    Map["green"] = "Time";
    Map["blue"] = "Space";
    Map["orange"] = "Soul";
    Map["red"] = "Reality";
    Map["yellow"] = "Mind";

    for(int i=0; i<n; i++){
        cin>>str;
        Map[str] = "";
    }

    vector<string>ans;
    for(auto it : Map){
        if(it.second.size()>0){
            ans.push_back(it.second);
        }
    }
    cout<<ans.size()<<endl;
    for(auto it : ans){
        cout<<it<<endl;
    }
    return 0;
}
