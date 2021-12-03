#include <bits/stdc++.h>
using namespace std;
string s1;
vector<string>V;

inline bool cmp(string a, string b) {
    return a<b;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, J, len, i, total;
    scanf("%d\n\n", &test);
    for(int t=0; t<test; t++){
        total = 0;
        if(t)puts("");
        map<string, int>M;
        V.clear();
        while(getline(cin, s1) && s1[0]) {
            if(M[s1]==0) {
                V.push_back(s1);
            }
            M[s1]++;
            total++;
        }
        sort(V.begin(), V.end(), cmp);
        len = V.size();
        for(i=0; i<len; i++){
            cout<<V[i];
            printf(" %.4lf\n", (double)(M[V[i]])/total*100);
        }
    }
    return 0;
}
