#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    cout<<min(a+b+c, min(a*2+b*2, min(a*2+c*2, b*2+c*2)))<<endl;
    return 0;
}
