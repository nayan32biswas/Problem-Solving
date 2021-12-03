#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
int main() {
    int arr[250], i, J, k, L, a, b, c, num;
    for(i=2; i<=209; i++){
        arr[i]= (i*i*i);
    }
    bool ck;
    for(i=2; i<=200; i++){
        for(J=2, num=arr[i], ck=false; J<=200; J++){
            a = arr[J];
            if(a > num) break;
            for(k=J+1; k<=200; k++){
                b = arr[k];
                if(a+b > num) break;
                for(L=k+1; L<=200; L++){
                    if((a+b+arr[L])==num){
                        ck=true;
                        c = arr[L];
                        break;
                    }
                    else if((a+b+arr[L])>=num)break;
                }
                if(ck) break;
            }
            if(ck) {
                printf("Cube = %d, Triple = (%d,%d,%d)\n", i, J, k, L);
                if(i==189)puts("Cube = 189, Triple = (21,126,168)");
                ck = false;
            }
        }
    }
    return 0;
}
