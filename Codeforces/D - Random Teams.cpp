#include <bits/stdc++.h>
using namespace std;
long long se(int num){num--; return (((long long)num*(num+1))/2);}
int main()
{
    //freopen("input.txt", "r", stdin);
    long long lo, hi, Min, average, lastTeam;
    int member, team;
    cin>>member>>team;
    if(team>=member) return puts("0 0"), 0;
    lo = member%team;
    hi = member/team;
    average = se(hi+1)*lo;
    lastTeam = se(hi)*(team-lo);
    printf("%lld %lld\n", average+lastTeam, se(member-(team-1)));
    return 0;
}
