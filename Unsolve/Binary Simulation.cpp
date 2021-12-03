#include <bits/stdc++.h>
using namespace std;
#define Size 100009
bool segt[Size*4];
char str[Size];
bool Find(int qlo, int lo, int hi, int pos)
{
    if(lo==hi)
    {
        bool ck=0;
        if(str[qlo]=='1') ck = 1;
        if(segt[pos])return !ck;
        else return ck;
    }
    int left = pos*2+1, right = pos*2+2;
    if(segt[pos])
    {
        segt[pos] = 0;
        segt[left] = !segt[left];
        segt[right] = !segt[right];
    }
    int mid = (lo+hi)>>1;
    if(qlo<=mid) return Find(qlo, lo, mid, left);
    return Find(qlo, mid+1, hi, right);
}
void update(int qlo, int qhi, int lo, int hi, int pos)
{
    if(lo>hi) return;
    if(lo>=qlo && hi<=qhi)  // total overlap
    {
        segt[pos] = !segt[pos];
        return;
    }
    if(qlo>hi || qhi<lo) return;// no overlap
    int left = pos*2+1, right = pos*2+2;
    if(segt[pos])
    {
        segt[pos] = 0;
        segt[left] = !segt[left];
        segt[right] = !segt[right];
    }
    int mid = (lo+hi)>>1;
    update(qlo, qhi, lo, mid, left);
    update(qlo, qhi, mid+1, hi, right);
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    cin>>test;
    for(int t=1; t<=test; t++)
    {
        printf("Case %d:\n", t);
        memset(segt, 0, sizeof(segt));
        cin.ignore();
        scanf("%s", str);
        int len = strlen(str);
        len--;
        int x, y, n;
        char c;
        scanf("%d", &n);
        while(n--)
        {
            cin.ignore();
            scanf("%c%d", &c, &x);
            x--;
            if(c=='Q')
            {
                printf("%d\n", Find(x, 0, len, 0));
            }
            else
            {
                scanf("%d", &y);
                y--;
                update(x, y, 0, len, 0);
            }
        }
    }
    return 0;
}

