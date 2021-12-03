#include <iostream>
using namespace std;
int main()
{
    string c;
    cin>>c;
    int len = c.size(), x=0;
    for(int i=0; i<len; i++){
        if(c[i]=='4' || c[i]=='7')
            x++;
    }
    if(x==4 || x==7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
