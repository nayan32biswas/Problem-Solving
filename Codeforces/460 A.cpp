#include <iostream>
using namespace std;
int main()
{
    int n, m, i, j;
    cin>>n>>m;
    for(i=1, j=1; i<=n; i++)if(j*m==i) n++, j++;
    cout<<n<<endl;
}
