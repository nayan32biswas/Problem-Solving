#include <bits/stdc++.h>
using namespace std;
string vowel="aeiou";
string CON="bcdfghjklmnpqrstvwxz";

int main()
{
    int n, i, J, k, l, x, y;
    cin>>n;
    if(n==1){
        for(i=97; i<123; i++){
            if(i=='y')continue;
            printf("%c\n", i);
        }
    }
    else if(n==2){
       for(i=0; i<5; i++) for(J=0; J<20; J++){
            printf("%c%c\n", vowel[i], CON[J]);
       }
       for(i=0; i<20; i++) for(J=0; J<5; J++){
                printf("%c%c\n", CON[i], vowel[J]);
       }
    }
    else if(n==3){
        for(i=0; i<5; i++) for(J=0; J<20; J++) for(k=0; k<5; k++){
            printf("%c%c%c\n", vowel[i], CON[J], vowel[k]);
        }
       for(i=0; i<20; i++) for(J=0; J<5; J++) for(k=0; k<20; k++){
            printf("%c%c%c\n", CON[i], vowel[J], CON[k]);
       }
    }
    else if(n==4){
        for(i=0; i<5; i++) for(J=0; J<20; J++) for(k=0; k<5; k++) for(l=0; l<20; l++){
            printf("%c%c%c%c\n", vowel[i], CON[J], vowel[k], CON[l]);
        }
       for(i=0; i<20; i++) for(J=0; J<5; J++) for(k=0; k<20; k++) for(l=0; l<5; l++){
            printf("%c%c%c%c\n", CON[i], vowel[J], CON[k], vowel[l]);
       }
    }
    else if(n==5){
        for(i=0; i<5; i++) for(J=0; J<20; J++) for(k=0; k<5; k++) for(l=0; l<20; l++) for(x=0; x<5; x++){
            printf("%c%c%c%c%c\n", vowel[i], CON[J], vowel[k], CON[l], vowel[x]);
        }
       for(i=0; i<20; i++) for(J=0; J<5; J++) for(k=0; k<20; k++) for(l=0; l<5; l++)for(x=0; x<20; x++){
            printf("%c%c%c%c%c\n", CON[i], vowel[J], CON[k], vowel[l], CON[x]);
       }
    }
    else{
        for(i=0; i<5; i++) for(J=0; J<20; J++) for(k=0; k<5; k++) for(l=0; l<20; l++) for(x=0; x<5; x++) for(y=0; y<20; y++){
            printf("%c%c%c%c%c%c\n", vowel[i], CON[J], vowel[k], CON[l], vowel[x], CON[y]);
        }
       for(i=0; i<20; i++) for(J=0; J<5; J++) for(k=0; k<20; k++) for(l=0; l<5; l++)for(x=0; x<20; x++) for(y=0; y<5; y++){
            printf("%c%c%c%c%c%c\n", CON[i], vowel[J], CON[k], vowel[l], CON[x], vowel[y]);
       }
    }
    return 0;
}
