#include<bits/stdc++.h>
using namespace std;

int main() {
    int tot=0,i;
    for (i=1;;++i) {
        if (tot+i>100000)break;
        tot+=i;
    }
    cout<<i<<endl;
}
