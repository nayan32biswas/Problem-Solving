#include <bits/stdc++.h>
using namespace std;
/** A;
int main()
{
    int siz, test, t, temp;
    stack<int>n;
    cin>>test;
    for(t=1; t<=test; t++){
        cin>>siz;
        for(i=0; i<siz; i++){
            cin>>temp;
            n.push(temp);
        }
        i=0;
        while(!n.empty()){
            if(i!=0) cout<<' ';
            cout<<n.top();
            n.pop();
            i++;
        }
        cout<<endl;
    }
}*/
/**B
void B(int n){
    if(n==0) return;
    cout<<n<<endl;
    B(n-1);
}
int main()
{
    int temp;
    cin>>temp;
    B(temp);
    return 0;
}*/
/* C
int C(int n){
    return n/3;
}
int main()
{
    int t, test, n, ans;
    cin>>test;
    for(t=1; t<=test; t++){
        cin>>n;
        cout<<C(n)+1<<endl;
    }
    return 0;
}*/
