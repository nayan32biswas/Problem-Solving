#include <bits/stdc++.h>
using namespace std;
int Find(unsigned long long n){
    if(n<10) return n;
    unsigned long long x = 0;
    while(n){
        x += n%10;
        n/=10;
    }
    return Find(x);
}
int main()
{
    string str;
    int p;
    cin>>str>>p;
    unsigned long long value = 0;
    for(int i=0; str[i]; i++) value+=(str[i]-'0');
    cout<<Find(value*p)<<endl;
}
