#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define SIZE 1000000
bool mark[400000000];
map<ull, bool>Mark;
int main()
{
    ull root, hight, b, c, ans, temp=1;
    for(root=1; temp<400000000; root++){
        temp = (root*root);
        mark[temp]=true;
    }
    for(; root<SIZE; root++){
        temp = (root*root);
        Mark[temp]=true;
    }
    while(cin>>hight){
        bool ck=false;
        ans = hight*hight;
        b = hight+1;
        temp = ans+(b*b);
        while(temp<400000000 && b<SIZE){
            if(mark[temp]){
                ck=true;
                break;
            }
            b++;
            temp = ans+(b*b);
        }
        if(!ck){
            while(!Mark[temp])b++, temp=ans+(b*b);
        }
        ans = (ull)sqrt(ans+(b*b));
        printf("%llu %llu %llu\n", hight, b, ans);
    }
}
