#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define LMT 32009
using namespace std;
int prime[LMT+5], dis[LMT+5];
bool pri[LMT+5];
void seive()
{
    int i, J, root=sqrt(LMT)+2, past;

    for(i=3; i<root; i+=2)if(!pri[i])
        for(J=i*i; J<LMT; J+=i*2) pri[J]=1;

    for(prime[0]=2, past=2, i=3, J=1; i<LMT; i+=2)
    {
        if(!pri[i])
        {
            prime[J]=i;
            dis[J-1]=i-past;
            past = i, J++;
        }
    }
}
int bainary(int key)
{
    int mid, start=0, End=3432;
    while(start<=End)
    {
        mid = (start+End)>>1;
        if(prime[mid]==key) break;
        else if(prime[mid]<key) start = mid+1;
        else End = mid-1;
    }
    return mid;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    seive();
    int i, J, x, y, ans, temp;
    while(scanf("%d%d", &x, &y)==2 && (x || y))
    {
        if(x>y) swap(x, y);
        i = bainary(x);
        for(ans=0, temp=dis[i-1]; prime[i]<=y; i++)
        {
            if(temp==dis[i])
            {
                ans++;
                continue;
            }
            J=(i-ans)-1;
            if(ans>0 && prime[J]>=x)
            {
                printf("%d", prime[J++]);
                for(; ans>=0; ans--, J++)
                    printf(" %d", prime[J]);
                puts("");
                ans = 0, temp = dis[i];
            }
            else ans = 0, temp = dis[i];
        }
    }
    return 0;
}
