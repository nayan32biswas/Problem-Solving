#include <bits/stdc++.h>
using namespace std;
vector<int>bord[100050];
int J;
bool ck(int i){
    int len = bord[i].size();
    for(int k=0; k<len; k++){
        if(bord[i][k]==J) return false;
    }
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int Qrow, Qcloum, row, cloum, siz, test, i,  ans=0;
    scanf("%d%d%d%d", &siz, &test, &Qcloum, &Qrow);
    Qcloum=abs(siz-Qcloum);
    Qrow--;
    for(i=0; i<test; i++){
        scanf("%d%d", &cloum, &row);
        row--;
        cloum=abs(siz-cloum);
        bord[cloum].push_back(row);
    }
    for(i=Qcloum-1, J=Qrow; i>=0 && ck(i)==true; i--, ans++);/// Up

    for(i=Qcloum+1, J=Qrow; i<siz && ck(i)==true; i++, ans++);/// Down

    for(i=Qcloum, J=Qrow-1; J>=0 && ck(i)==true; J--, ans++);/// left

    for(i=Qcloum, J=Qrow+1; J<siz && ck(i)==true; J++, ans++);/// right

    for(i=Qcloum-1, J=Qrow-1; i>=0 && J>=0 && ck(i)==true; i--, J--, ans++);/// up L

    for(i=Qcloum-1, J=Qrow+1; i>=0 && J<siz && ck(i)==true; i--, J++, ans++);/// up R

    for(i=Qcloum+1, J=Qrow-1; i<siz && J>=0 && ck(i)==true; i++, J--, ans++);/// Down L

    for(i=Qcloum+1, J=Qrow+1; i<siz && J<siz && ck(i)==true; i++, J++, ans++);/// Down R

    cout<<ans<<endl;

    return 0;
}



/*#include <bits/stdc++.h>
using namespace std;
bool bord[30000][50000];
int main()
{
    freopen("input.txt", "r", stdin);
    int Qrow, Qcloum, op_row, op_cloum, siz, test, i, J, ans=0;
    scanf("%d%d%d%d", &siz, &test, &Qcloum, &Qrow);
    Qcloum=abs(siz-Qcloum);
    Qrow--;
    for(i=0; i<test; i++){
        scanf("%d%d", &op_cloum, &op_row);
        op_row--;
        op_cloum=abs(siz-op_cloum);
        bord[op_cloum][op_row]=1;
    }
    for(i=Qcloum-1, J=Qrow; i>=0 && bord[i][J]!=1; i--, ans++);/// Up
    for(i=Qcloum+1, J=Qrow; i<siz && bord[i][J]!=1; i++, ans++);/// Down
    for(i=Qcloum, J=Qrow-1; J>=0 && bord[i][J]!=1; J--, ans++);/// left
    for(i=Qcloum, J=Qrow+1; J<siz && bord[i][J]!=1; J++, ans++);/// right
    for(i=Qcloum-1, J=Qrow-1; i>=0 && J>=0 && bord[i][J]!=1; i--, J--, ans++);/// up L
    for(i=Qcloum-1, J=Qrow+1; i>=0 && J<siz && bord[i][J]!=1; i--, J++, ans++);/// up R
    for(i=Qcloum+1, J=Qrow-1; i<siz && J>=0 && bord[i][J]!=1; i++, J--, ans++);/// Down L
    for(i=Qcloum+1, J=Qrow+1; i<siz && J<siz && bord[i][J]!=1; i++, J++, ans++);/// Down R
    cout<<ans<<endl;
    return 0;
}*/
