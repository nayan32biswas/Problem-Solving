#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define Size 1000000
int dis[Size];
char s[Size];
bool ck[130];
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, j, n, len;
    scanf("%s", s);
    len = strlen(s);
    for(i=0, j=0; i<len; i++){
        if(!ck[s[i]]){
            ck[s[i]] = true;
            j++;
        }
        dis[i+1]=j;
    }
    //for(i=1; i<=len; i++) cout<<dis[i]<<' ';cout<<endl;
    cin>>test;
    while(test--){
        scanf("%d", &n);
        printf("%d\n", dis[n]);
    }
}
