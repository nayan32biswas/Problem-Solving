#include<stdio.h>
int main()
{
    int sh,sm,eh,em,H,M;
    scanf("%d%d%d%d",&sh,&sm,&eh,&em);
    H=eh-sh;
    if(H<0)
        H=24+(eh-sh);
    M=em-sm;
    if(M<0){
        M=60+(em-sm);
        H--;
    }
    if(sh==eh && sm==sm){
            printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    }
    else
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n",H,M);
    return 0;
}
