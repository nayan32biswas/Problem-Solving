#include <iostream>
#include <algorithm>
#include <cstdio>
#define SIZ 111
using namespace std;
struct data {
    int pos, value;
    bool operator < (const data& a){
        if(value!=a.value) return value < a.value;
        return pos < a.pos;
    }
}line[SIZ];
char s[SIZ][SIZ];
inline int call(char s1[], int len) {
    int posi=0, i=0, J;
    for(; i<len; i++)
        for(J=i+1; J<len; J++)
            if(s1[i] > s1[J]) posi++;
    return posi;
}
int main() {
    //freopen("input.txt", "r", stdin);
    int len, i, test, many;
    scanf("%d", &test);
    for(int t=0; t<test; t++) {
        if(t) puts("");
        scanf("%d%d\n", &len, &many);
        for(i=0; i<many; i++) {
            scanf("%s", s[i]);
            line[i].pos = i;
            line[i].value = call(s[i], len);
        }
        sort(line, line+many);
        for(i=0; i<many; i++) {
            puts(s[line[i].pos]);
        }
    }
    return 0;
}


/*#include <bits/stdc++.h>
#define SIZ 9999
using namespace std;
vector<string>V[SIZ];
vector<int>p;
int position[SIZ];
int main() {
    freopen("input.txt", "r", stdin);
    char s[111];
    int len, i, test, J, pos, many;
    scanf("%d", &test);
    for(int t=0; t<test; t++) {
        if(t) puts("");
        scanf("%d%d\n", &len, &many);

        p.clear(); memset(V, 0, sizeof(V));
        memset(position, 0, sizeof(position));
        while(many--) {
            scanf("%s", s);
            for(i=0, pos=0; i<len; i++)
                for(J=i+1; J<len; J++)
                    if(s[i] > s[J]) pos++;

            V[pos].push_back(s);
            if(position[pos]==0) p.push_back(pos);
            position[pos]++;
        }
        sort(p.begin(), p.end());
        many = p.size();
        for(i=0; i<many; i++) {
            pos = p[i];
            len = V[pos].size();
            for(J=0; J<len; J++){
                cout<<V[pos][J]<<endl;
            }
        }
    }
    return 0;
}*/
