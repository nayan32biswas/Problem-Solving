#include <iostream>
using namespace std;
bool arr[102];
int main()
{
    int i, n, p, x;
    cin>>n>>p;
    for(i=0; i<p; i++){
        cin>>x;
        arr[x]=1;
    }
    cin>>p;
    for(i=0; i<p; i++){
        cin>>x;
        arr[x]=1;
    }
    n++;
    for(i=1; i<n; i++)if(!arr[i])break;
    if(i==n) cout<<"I become the guy."<<endl;
    else cout<<"Oh, my keyboard!"<<endl;
}
