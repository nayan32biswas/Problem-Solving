#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s1, s;
int i, len, space=0;

int main()
{
    cin>>s;
    len = s.size();
    for(i=0, space=0; i<len; i++) {
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B'){
            if(s1.size()>0) {
                if(space>0) cout<<' ';
                cout<<s1;
                s1.clear();
                space++;
            }
            i+=2;
        }
        else{
            s1 = s1+s[i];
        }
    }
    if(s1.size()>0)cout<<' '<<s1;
    if(space) cout<<endl;
    return 0;
}
