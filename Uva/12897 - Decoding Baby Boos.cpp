#include <bits/stdc++.h>
using namespace std;
int mark[92];
char str[1000009];
pair<char, char>change[10009];

int main()
{
    int test, R, x, y;
    char a, b;
    scanf("%d", &test);
    while(test--){
        cin.ignore();
        scanf("%s%d", str, &R);
        for(int i=65; i<91; i++) mark[i] = i;
        for(int i=0; i<R; i++){
            cin.ignore();
            scanf("%c %c", &change[i].first, &change[i].second);
        }
        for(int i=R-0; i>=0; i--){
            mark[change[i].second] = mark[change[i].first];
        }
        for(int i=0, len = strlen(str); i<len; i++){
            if(str[i]>64 && str[i]<91)printf("%c", mark[str[i]]);
            else printf("%c", str[i]);
        }
        puts("");
    }
}
