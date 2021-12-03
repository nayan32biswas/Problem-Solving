#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int test, i, j, len, len1, Max;
    string s, ans, temp;
    scanf("%d\n", &test);
    while(test--) {
        map<string, int>M;
        cin>>s;
        len = s.size();
        for(i=0, Max=9999; i<len; i++) {
            temp.clear();
            temp+=s[i];
            for(j=i+1; j<len; j++) {
                temp+=s[j];
                cout<<s.find(temp)<<' '<<temp<<'\t';
                M[temp]++;
            }
            cout<<endl;
        }
        //cout<<ans<<' '<<ans.size()<<endl;
        if(test) puts("");
    }
    return 0;
}
