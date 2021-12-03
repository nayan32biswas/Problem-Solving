#include <bits/stdc++.h>
using namespace std;
#define Size 10000
int prime[Size/5];
bool pir[Size];
int main()
{
    for(int i=4; i<Size; i+=2) pir[i]=true;
    pir[1] = true;
    for(int i=3; i*i<=Size; i+=2){
        if(pir[i]==false){
            for(int j=i*i; j<Size; j+=(i*2)){
                pir[j] = true;
            }
        }
    }
    prime[0] = 2;
    for(int i=3, j=1; i<Size; i+=2) {
        if(pir[i]==false){
            prime[j++] = i;
        }
    }
    for(int i=0; i<200; i++)
        cout<<prime[i]<<" ";
    cout<<endl;
    return 0;
}

