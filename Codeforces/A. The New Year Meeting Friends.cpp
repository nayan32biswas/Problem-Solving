#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c, Min=999, i, temp;
    cin>>a>>b>>c;
    int Max = max(a, max(b, c));
    for(i=1; i<=Max; i++) {
        temp = (abs(i-a)+abs(i-b)+abs(i-c));
        if(temp<Min) Min = temp;
    }
    cout<<Min<<endl;
}
