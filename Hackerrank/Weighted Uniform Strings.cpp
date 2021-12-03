#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool arr[100000000];
char s[100009], c;
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%s", s);
    int len, i, x, test, num, sum, t;
    c = s[i];
    for(i=0, sum=0; s[i]; i++){
        sum+=(s[i]-96);
        arr[sum]=1;
        if(s[i+1]!=c){
            c = s[i+1];
            sum = 0;
        }
    }
    scanf("%d", &test);
    for(t=0; t<test; t++){
        scanf("%d", &num);
        if(arr[num]==1) puts("Yes");
        else puts("No");
    }
    return 0;
}
