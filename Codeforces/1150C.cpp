#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, one=0, two=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x);
        x==1 ? one++ : two++;
    }
    if(two)printf("2"), two--;
    if(one)printf(" 1"), one--;
    while(two--) printf(" 2");
    while(one--) printf(" 1");
    puts("");
    return 0;
}