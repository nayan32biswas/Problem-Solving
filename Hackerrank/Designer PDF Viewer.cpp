#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int arr[30];
char s[20];
int main()
{
    int i, len, Max=0, x;
    for(i=0; i<26; i++){
        scanf("%d", &arr[i]);
    }
    cin>>s;
    len = strlen(s);
    for(i=0; i<len; i++){
        x = arr[s[i]-97];
        if(x>Max) Max = x;
    }
    printf("%d\n", Max*len);
    return 0;
}
