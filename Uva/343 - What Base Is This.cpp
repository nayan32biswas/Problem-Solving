#include <bits/stdc++.h>
using namespace std;
void fil(int *value1, int *value2)
{
    for(int i=0; i<39; i++){
        value1 [i] = -1;
        value2 [i] = -2;
    }
}
int power(int num, int po)
{
    int ans = 1, k;
    for(k=1; k<=po; k++) ans *= num;
    return ans;
}
void ToTen(char *a, int *value)
{
    int temp, start, i, j, sum;
    int len = strlen(a);

    for(i=0, start=0; i<len; i++){
        a[i]<59 ? temp=a[i]-48 : temp=a[i]-55;
        start = max (start, temp);
    }
    for(i=start+1; i<=36; i++){
        for(j=len-1, sum = 0; j>=0; j--) {
            a[j]<59 ? temp=a[j]-48 : temp=a[j]-55;
            sum += (temp * power(i, len-1-j));
        }
        value[i] = sum;
    }
}
int main ()
{
    //freopen("input.txt", "r", stdin);
    int value1[39], value2[39], i, j;
    char first[200], second[200];
    bool ck;

    while(scanf("%s%s", first, second)!=EOF) {
        fil(value1, value2);

        ToTen(first, value1);
        ToTen(second, value2);

        for (i=2, ck=false; i<=36; i++){
            for(j=2; j<=36; j++){
                if (value1[i] == value2[j]){
                    printf ("%s (base %d) = %s (base %d)\n", first, i, second, j);
                    ck=true;break;
                }
            }
            if(ck) break;
        }
        if(!ck)printf ("%s is not equal to %s in any base 2..36\n", first, second);
    }
    return 0;
}
