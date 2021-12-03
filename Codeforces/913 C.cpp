#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define Size 33

struct data{
    int roubles, litter;
    double par_litters;
}arr[Size];
bool comp(data &T, data &TT){
    if(T.par_litters==TT.par_litters)
        return T.roubles>TT.roubles;
    return T.par_litters<TT.par_litters;
}
bool ck;
int n, L;
void store();
ull rec(int pos){
    if(L<1) return 0;
    if(pos==n) return (1+L/arr[pos-1].litter)*arr[pos-1].roubles;
    if(L%arr[pos].litter==0) return (L/arr[pos].litter)*arr[pos].roubles;

    int bad = (L/arr[pos].litter);
    L -= bad*arr[pos].litter;
    ull remainde = bad*arr[pos].roubles;
    ull total = (bad+1)*arr[pos].roubles;
    cout<<(bad+1)*arr[pos].roubles<<" "<<total<<" "<<bad<<" "<<arr[pos].roubles<<" "<<remainde<<endl;
    return min(total, remainde+rec(pos+1));

}
int main(){
    freopen("input.txt", "r", stdin);
    cin>>n>>L;
    ull p = 1;
    arr[0].litter = 1;
    for(int i=0; i<n; i++){
        cin>>arr[i].roubles;
        if(i){
            arr[i].par_litters = arr[i].roubles/(p*=2);
            arr[i].litter = p;
        }
        else arr[i].par_litters = arr[i].roubles;
    }
    sort(arr, arr+n, comp);
    for(int i=0; i<n; i++){
        cout<<arr[i].roubles<<" "<<arr[i].par_litters<<" "<<arr[i].litter<<endl;
    }
    cout<<rec(0)<<endl;
    return 0;
}
