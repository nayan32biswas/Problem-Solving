#include <bits/stdc++.h>
using namespace std;
#define Size 400005
char str[Size];
int main()
{
    int n, k;
    scanf("%d%d%s", &n, &k, str);
    for(char ch = 'a'; ch<='z' && k>0; ch++){
        for(int i=0; i<n && k>0; i++){
            if(str[i]==ch){
                str[i] = 0;
                k--;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(str[i]>0)printf("%c", str[i]);
    }
    return 0;
}


