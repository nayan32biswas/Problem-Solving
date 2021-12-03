#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s;
int longest, many;
bool ck;
int main()
{
    int len, i, j;
    cin>>len>>s;

    for(i=0, j=0; i<len; i++) {
        if(s[i]=='('){
            j = 0;
            while(s[i]!=')'){
                ck = false;
                i++;
                for(; i<len; i++) {
                    if(s[i]==')' || s[i]=='_') break;
                    ck = true;
                }
                if(ck) many++;
            }
        }
        else if(s[i]!='_') j++;
        else j=0;
        longest = max(longest, j);
    }
    cout<<longest<<' '<<many<<endl;
    return 0;
}
