#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<ull, bool>Map;
vector<pair<ull, ull>>List;
int main(){
    ull l, r, hiPrime = 2;
    cin>>l>>r;
    int time = clock();
    ull dis = (r-l+1)/2;
    for(ull i=l; i<r && dis>0; i++)if(!Map[i]){
        for(ull j=i+1; j<=r && dis>0; j++)if(!Map[j]){
            if(__gcd(i, j)==1){
                List.push_back(make_pair(j, i));
                Map[j] = true;
                Map[i] = true;
                dis--;
                break;
            }
        }
    }
    dis = (r-l+1)/2;
    //cout<<List.size()<<endl;
    if(List.size()>=dis){
        puts("YES");
        for(int i=0; i<dis; i++){
            cout<<List[i].first<<" "<<List[i].second<<endl;
            //printf("%ul %ul\n", List[i].first, List[i].second);
        }
    }
    else puts("NO");
    //cout<<clock()-time<<endl;
    return 0;
}
