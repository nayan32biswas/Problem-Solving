#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        char a[110][110];
        int b[110];
        bool x=true;

        for(int i=0; i<n; i++)
            cin>>b[i];

        getchar();
        for(int i=0; i<n; i++)
            gets(a[i]);

        for(int i=0; i<n; i++){
            int len,cou=0;
            len=strlen(a[i]);
            for(int j=0; j<len; j++){
                if(a[i][j]=='a' || a[i][j]=='e' || a[i][j]=='i' || a[i][j]=='o' || a[i][j]=='u'||a[i][j]=='y')
                    cou++;
            }
            if(cou!=b[i]){
                x=false;
                break;
            }
        }
        if(x==false)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
