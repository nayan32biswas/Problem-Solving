#include <iostream>
#include <cstdio>
using namespace std;
void nort(int stage[]){
    int temp = stage[0];
    stage[0] = stage[3];
    stage[3] = stage[1];
    stage[1] = stage[2];
    stage[2] = temp;
}
void sout(int stage[]){
    int temp = stage[0];
    stage[0] = stage[2];
    stage[2] = stage[1];
    stage[1] = stage[3];
    stage[3] = temp;
}
void eas(int stage[]){
    int temp = stage[0];
    stage[0] = stage[5];
    stage[5] = stage[1];
    stage[1] = stage[4];
    stage[4] = temp;
}
void was(int stage[]){
    int temp = stage[0];
    stage[0] = stage[4];
    stage[4] = stage[1];
    stage[1] = stage[5];
    stage[5] = temp;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    char s[6];
    while(scanf("%d", &n) && n){
        int stage[] = {1, 6, 2, 5, 4, 3};
        for(int i=0; i<n; i++){
            scanf("%s", s);
            if(s[0]=='n') nort(stage);
            else if(s[0]=='s') sout(stage);
            else if(s[0]=='e') eas(stage);
            else if(s[0]=='w') was(stage);

        }
        printf("%d\n", stage[0]);
    }
    return 0;
}
