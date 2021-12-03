#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a, b, i;
    cin>>a>>b;
    for(i=1; ;){
        if(i&1){
            a-=i; i++;
            if(b<i) return puts("Valera"), 0;
        }
        else{
            b-=i; i++;
            if(a<i) return puts("Vladik"), 0;
        }
    }
}
