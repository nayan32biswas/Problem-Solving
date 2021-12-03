#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, int>M;
    int Max, len, N, i, j;
    string ans, s, temp;

    while(cin>>N>>s){
        M.clear();
        temp.clear();

        len = s.size();
        for(i=0; i<N; i++) temp+=s[i];

        M[temp]++;
        ans = temp;
        Max = 1;
        for(; i<len; i++){
            temp.erase(temp.begin());
            temp+=s[i];
            j = ++M[temp];
            if(j>Max){
                Max = j;
                ans = temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
