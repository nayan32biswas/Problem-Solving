#include <iostream>
using namespace std;
int main()
{
    string x, y;
    int len, len1, MAX, MIN;
    cin>>x>>y;
    len = x.size();
    len1 = y.size();
    len > len1 ? MIN = len1 : MIN = len;
    len < len1 ? MAX = len1 : MAX = len;
    for(int i=0; i<MAX; ++i){
        if(i<MIN) {
            if(x[i] == y[i]) {
                    cout<<'0';
            }
            else {
                if(x[i]=='1' || y[i]=='1')
                    cout<<'1';
                else
                    cout<<'0';
            }
        }
        else{
            if(MAX==len)
                for(i=MIN; i<MAX; ++i)
                    cout<<x[i];
            else
                for(i=MIN; i<MAX; ++i)
                    cout<<y[i];
        }
    }
    cout<<endl;

    return 0;
}
