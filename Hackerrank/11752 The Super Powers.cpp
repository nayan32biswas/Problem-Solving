#include <bits/stdc++.h>
using namespace std;
#define INF ULLONG_MAX
#define Size 10000000
typedef unsigned long long int ull;
map<ull, int>Map;
int main() {
    ull x=1, POW=0, past;
    for(int i=2; i<Size; i++) {
        x = i;
        while(x<INF) {
            past = x;
            x *= i;
            if(x<past)
                break;
            POW++;
            Map[x]++;
        }
    }

    cout<<clock()<<endl;

    x=0;
    cout<<1<<endl;
    for(auto it : Map) {
        if(it.second>1){
            //cout<<it.first<<endl;
            x++;
        }
    }
    cout<<x<<endl;
    cout<<clock()<<endl;
    return 0;
}
