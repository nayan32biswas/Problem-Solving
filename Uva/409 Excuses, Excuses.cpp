#include <bits/stdc++.h>
using namespace std;
#define Size 22
map<int, vector<int> >ans;
int Find(string str, vector<string>key) {
    string s = "";
    map<string, int> Map;
    for(auto it : str) {
        if(it<='Z' && it>='A') it += 32;
        if(it>='a' && it<='z')
            s += it;
        else if(s != "") {
            Map[s]++;
            s = "";
        }
    }
    if(s != "")
        Map[s]++;
    int coun = 0;
    for(auto it : key)
        coun += Map[it];
    return coun;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int K, E, t = 0;
    while(cin>>K>>E) {
        vector<string>key(K), excuses(E);
        ans.clear();
        for(int i=0; i<K; i++)
            cin>>key[i];
        cin.ignore();
        for(int i=0; i<E; i++) {
            getline(cin, excuses[i]);
            int x = Find(excuses[i], key);
            ans[x].push_back(i);
        }

        printf("Excuse Set #%d\n", ++t);
        for(auto it : ans.rbegin()->second)
            cout<<excuses[it]<<endl;
        puts("");
    }
    return 0;
}
