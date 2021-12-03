#include <iostream>
using namespace std;
int main()
{
    int n, p, q, ans=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>p>>q;
        if(q-2>=p)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
