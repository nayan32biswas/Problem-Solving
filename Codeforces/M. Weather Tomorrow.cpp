#include <bits/stdc++.h>
using namespace std;
int seq[101];
int dis(int a, int b){
    int x;
    if((a<=0 && b<=0)||( a>0 && b>0 )){
        x = a-b;
    }
    else x = abs(a)+abs(b);
    if(a>b) return -x;
    else return abs(x);
}
int main()
{
    int n, first, last;
    cin>>n>>first;
    for(int i=1; i<n; i++){
        cin>>last;
        seq[i-1] = dis(first, last);
        first = last;
    }
    //for(int i=0; i<n-1; i++) cout<<seq[i]<<' ';puts("");
    n-=2;
    for(int i=0; i<n; i++){
        if(seq[i]==seq[i+1]) continue;
        else{
            printf("%d\n", last);
            return 0;
        }
    }
    cout<<last+seq[0]<<endl;
}
