#include<bits/stdc++.h>
using namespace std;
int i,j,m,n,a,c[20][20];
string s1 = "algorithm", s2 = "alignment";
char b[20][20];
void print_lcs(int i,int j) {
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c') {
        print_lcs(i-1,j-1);
        printf("%c",s1[i-1]);
    } else if(b[i][j]=='u')
        print_lcs(i-1,j);
    else
        print_lcs(i,j-1);
}
void lcs_length(void) {
    m = (int)s1.size();
    n = (int)s2.size();
    for(int i=0; i<=m; i++)
        c[i][0]=0;
    for(int i=0; i<=n; i++)
        c[0][i]=0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) {
            if(s1[i-1]==s2[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='c';
            } else if(c[i-1][j]>c[i][j-1]) {
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            } else {
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }
        }
    print_lcs(m,n);
}
int main() {
    printf("longest common subsequence is : ");
    lcs_length();
    return 0;

}
