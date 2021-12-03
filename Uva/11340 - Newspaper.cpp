#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int N, K, m, i, j, len, yy;
    double X;
    map<char, int> M;
    char c;
    char s[10000];
    scanf("%d", &N);
    for(int t=0; t<N; t++) {
        scanf("%d\n", &K);
        M.clear();
        X = 0;
        while(K--) {
            scanf("%c%d\n", &c, &yy);
            M[c]=yy;
        }
        scanf("%d\n", &m);
        while(m--) {
            gets(s);
            len = strlen(s);
            for(i=0; i<len; i++) {
                X+=M[s[i]];
            }
        }
        X/=100;
        printf("%.2lf", X);
        puts("$");
    }
    return 0;
}
