#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    map<int, int>Map;
    vector<int>num;
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(Map[n])
            Map[n]++;
        else {
            num.push_back(n);
            Map[n]++;
        }
    }
    for(auto it : num)
        printf("%d %d\n", it, Map[it]);
    return 0;
}
