#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n, exit, inter, people, ans;
    cin>>n;
    cin>>exit>>inter;
    people=exit-inter;
    people=fabs(people);
    ans=people;
    for(int i=1; i<n; i++){
        scanf("%d%d", &exit, &inter);
        people -= exit;
        people += inter;
        ans=max(ans, people);
    }
    cout<<ans<<endl;
    return 0;
}
