#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    //freopen("Input.txt", "r", stdin);
    char s[2000];
    int T, N, len, i, J, t, x;
    bool ck;
    cin>>T;
    for(t=1; t<=T; t++){
        scanf("%d\n", &N);
        if(t!=1)
            cout<<endl;
        printf("Case %d:\n", t);
        for(J=0; J<N; J++){
            gets(s);
            ck=true;
            len = strlen(s);
            for(i=0; i<len; i++){
                if(s[i]==' ' && ck==true){
                    cout<<' ';
                    ck = false;
                    continue;
                }
                if(s[i]==' ') continue;
                printf("%c", s[i]);
                ck=true;
            }
            cout<<endl;
        }
    }
    return 0;
}
