#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

char s[500009];
int A[500009], C[500009], lenA, lenB, lenC;

map<long long, bool>BBB;
bool b[100000001];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i, j, ans;
    long long temp, Max=0;
    scanf("%d%s", &n, s);
    for(i=0; i<n; i++){
        if(s[i]=='b'){
            i++;
            temp = (long long)i*i;
            if(i<10000) b[temp]=1;
            else BBB[temp]=1;
            Max = max(Max, temp);
            i--;
        }
        else if(s[i]=='a') A[lenA++]=i+1;
        else C[lenC++]=i+1;
    }

    //for(i=0; i<lenA; i++) cout<<A[i]<<' ';cout<<endl;
    //for(i=0; i<lenC; i++) cout<<C[i]<<' ';cout<<endl<<endl<<endl;

    for(i=0, ans=0; i<lenA; i++){
        for(j=0, temp=0; j<lenC && temp<Max; j++){
            temp = (long long)A[i]*C[j];
            if(temp<100000000){
                if(b[temp]==1){
                    ans++;
                }
            }
            else if(BBB[temp]==1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
