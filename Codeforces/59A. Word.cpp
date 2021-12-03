#include <bits/stdc++.h>
using namespace std;
int main()
{
    string c;
    int up=0, lo=0, len;
    cin>>c;
    len = c.size();
    for(int i=0; i<len; i++){
        if(c[i]>90) lo++;
        else up++;
    }
    if(lo<up){
        for(int i=0; i<len; ++i) {
            if(c[i]>90) c[i]-=32;
        }
    }
    else if(lo>up) {
        for(int i=0; i<len; ++i) {
            if(c[i]<97) c[i]+=32;
        }
    }
    else{
        for(int i=0; i<len; ++i) {
            if(c[i]<97) c[i]+=32;
        }
    }
    cout<<c<<endl;
    return 0;
}
