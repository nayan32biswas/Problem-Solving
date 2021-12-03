#include<bits/stdc++.h>
using namespace std;
int used[20],number[20], valu, temp;
void permutation(int x, int n);
int main()
{
    int n, test;
    cin>>test;
    for(int t=1; t<=test; t++){
        temp=0;
        cin>>n>>valu;
        printf("Case %d:\n", t);
        permutation(1,n);
    }
    return 0;
}
void permutation(int x, int n)
{
    if(x==n+1 && temp!=valu){
        temp++;
        for(int i=1; i<=n; i++)
            printf("%c",number[i]);
        cout<<endl;
        return;
    }
    if(temp!=valu){
        for(int i=1; i<=n; i++) if(!used[i]){
            used[i] = 1;
            number[x] = i+64;
            permutation(x+1,n);
            used[i] = 0;
        }
    }
}
