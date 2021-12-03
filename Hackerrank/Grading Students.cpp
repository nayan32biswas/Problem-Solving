#include <iostream>
using namespace std;
int main()
{
    int test, num, rem;
    cin>>test;
    for(int t=0; t<test; t++){
        cin>>num;
        if(num<38){
            cout<<num<<endl;
            continue;
        }
        rem = num%5;
        if(rem<3){
            cout<<num<<endl;
            continue;
        }
        rem = 5-rem;
        cout<<(num+rem)<<endl;
    }
    return 0;
}
