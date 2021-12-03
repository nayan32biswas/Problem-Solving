#include <bits/stdc++.h>
using namespace std;
char str[110];
void Reverse(int j){
    for(int i=1; i<j; i++, j--)
        swap(str[i], str[j]);
}
int main()
{
    int n;
    cin>>n>>str;
    for(int i=n; i>0; i--) str[i] = str[i-1];
    str[n+1]=0;
    for(int i=2; i<=n; i++){
        if(n%i==0){
            Reverse(i);
        }
    }
    for(int i=1; i<=n; i++) printf("%c", str[i]);
    puts("");
    return 0;
}

