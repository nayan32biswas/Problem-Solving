#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    char s[88];
    int test, ans, i, j;
    scanf("%d", &test);
    while(test--){
        scanf("%s", s);
        for(i=0, ans=0, j=1; s[i]; i++){
            if(s[i]=='X') j=0;
            ans+=j;
            j++;
        }
        printf("%d\n", ans);
    }
}
