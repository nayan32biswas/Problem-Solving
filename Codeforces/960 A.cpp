#include <bits/stdc++.h>
using namespace std;
int a, b, c, i;
int main()
{
    string str;
    cin>>str;
    for(i=0; str[i]=='a' && str[i]; i++, a++);
    for(; str[i]=='b' && str[i]; i++, b++);
    for(; str[i]=='c' && str[i]; i++, c++);
    if(a && b && str.size()==(a+b+c) && (a==c || b==c)){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;

}
