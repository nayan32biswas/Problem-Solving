#include <iostream>
using namespace std;
int main()
{
    int n, steps=0;
    cin>>n;
    while(n>1){
        if(n&1){
            steps++;
            n++;
        }
        n>>=1;
        steps++;
    }
    cout<<steps<<endl;
}
