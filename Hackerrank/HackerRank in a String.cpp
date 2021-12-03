#include <bits/stdc++.h>
using namespace std;
char s[10200], arr[]={"hackerrank"};
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, i, J;
    scanf("%d\n", &test);
    bool ck, temp;
    for(int t=1; t<=test; t++){
        cin>>s;
        int len = strlen(s);
        ck = false;
        if(len>=10){
            for(i=0, J=0; i<len; i++){
                if(s[i]==arr[J]) J++;
                if(J==10){
                    ck = true;
                    break;
                }
            }
        }
        if(ck==true) puts("YES");
        else puts("NO");
    }
    return 0;
}
