#include <bits/stdc++.h>
using namespace std;
#define Size 3005
#define MAX 4000000000
unsigned sss[Size], ccc[Size];
char c;
template <typename T>
void read(T &x) {
    for(c=getchar(); (c<'0'||c>'9'); c=getchar());
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
}
int main()
{
    int n;
    unsigned ans=MAX;
    cin>>n;
    for(int i=0; i<n; i++)
        read(sss[i]);
    for(int i=0; i<n; i++)
        read(ccc[i]);
    unsigned left, right;
    for(int i=1; i<n-1; i++)
    {
        left = right = MAX;
        for(int j=i-1; j>=0; j--)
        {
            if(sss[j]<sss[i])
            {
                left = min(left, ccc[j]);
            }
        }
        for(int j=i+1; j<n; j++)
        {
            if(sss[i]<sss[j])
            {
                right = min(right, ccc[j]);
            }
        }
        //cout<<i<<" "<<left<<" "<<right<<endl;
        if(left!=MAX && right!=MAX){
            ans = min(ans, left+ccc[i]+right);
        }
    }
    if(ans == MAX)
    {
        puts("-1");
    }
    else
    {
        cout<<ans<<endl;
    }
    return 0;
}



