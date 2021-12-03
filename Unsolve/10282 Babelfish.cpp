#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    //freopen("Input.txt", "r", stdin);
    map<string, string>M;
    int i, J;
    char s[100], s1[100], s2[100];
    while(gets(s) && s[0]){
        for(i=0; s[i]!=' '; i++){
            s1[i]=s[i];
        }
        s1[i]=0;
        for(J=0,i++; s[i]; J++, i++){
            s2[J]=s[i];
        }
        s2[J]=0;
        M[s2]=s1;
    }
    while(gets(s) && s[0]){
        if(M[s].size()<=0)printf("eh\n");
        else
            cout<<M[s]<<endl;
    }
    return 0;
}
