#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, c, d, sum=0;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a%2==0 ? sum+=32 : sum+=256;
    if(b!=a) {b%2==0 ? sum+=32 : sum+=256;}
    if(c!=a && c!=b) {c%2==0 ? sum+=32 : sum+=256;}
    if(d!=a && d!=b && d!=c) {d%2==0 ? sum+=32 : sum+=256;}
    cout<<sum<<endl;
    return 0;
}
