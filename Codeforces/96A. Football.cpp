#include <iostream>
#include <string>
using namespace std;
int main()
{
    string c;
    cin>>c;
    int YES, temp, temp1, len = c.size();
    for(int i=0; i<len;){
        temp = c[i];
        YES=0;
        for(;i<len; i++){
            temp1=c[i];
            if(temp==temp1)
                YES++;
            if(temp!=temp1 || YES>=7){
                break;
            }
        }
        if(YES>=7) break;
    }
    if(YES>=7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
