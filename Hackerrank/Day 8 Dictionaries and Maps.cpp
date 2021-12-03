#include <bits/stdc++.h>
using namespace std;
map<string, bool>M;
char s[100050][100], s1[100], number[100050][100];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s %s", s[i], number[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%s", s1);
        M[s1]=true;
    }
    for(int i=0; i<n; i++){
        if(M[s[i]]==true){
            printf("%s=%s\n", s[i], number[i]);
            M[s[i]]=false;
        }
        else puts("Not found");
    }
    return 0;
}
