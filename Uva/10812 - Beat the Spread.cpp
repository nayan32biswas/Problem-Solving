#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    bool ck;
    int test, sum, absulate, i, j, winer, looser;
    cin>>test;
    while(test--){
        cin>>sum>>absulate;
        looser = 0, winer = absulate;
        ck = false;
        while(!ck && winer<=sum){
            if((winer+looser)==sum){
                ck=true;
                cout<<winer<<' '<<looser<<endl;
            }
            looser++, winer++;
        }
        if(!ck){
            cout<<"impossible"<<endl;
        }
    }
    return 0;
}
