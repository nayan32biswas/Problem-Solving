#include <bits/stdc++.h>
using namespace std;
#define Size 2000009
char str[Size];
int vis[Size];
vector< pair<int, int> >vec;
int main() {
    int n, x;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &x);
        if(x>i)
            vec.push_back(make_pair((x-i), x));
        else if(x<i)
            vec.push_back(make_pair((i-x), i));
    }
    bool check = false;
    for(int i=0; i<=n; i++){
        str[i] = getchar();
        if(!check && str[i]=='0') check = true;
    }
    if(!check)return puts("YES"), 0;

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(auto it : vec) {
        int lo = it.second-it.first, hi = it.second;
        if(!vis[lo]) {
            for(int i=lo; i<hi; i++) {
                if(str[i]=='0') {
                    return puts("NO"), 0;
                }
                if(vis[i])
                    i = vis[i];
            }
            hi--;
            for(int i=lo; i<hi; i++)
                vis[i] = hi;
        }
    }
    puts("Yes");
    return 0;
}
