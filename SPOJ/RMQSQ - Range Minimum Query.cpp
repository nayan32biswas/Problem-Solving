#include <bits/stdc++.h>
using namespace std;
#define Size 300009
int segt[Size], input[100009];
void cons_segt(int lo, int hi, int pos){
    if(lo==hi){
        segt[pos] = input[lo];
        return;
    }
    int mid = (lo+hi)>>1;
    cons_segt(lo, mid, pos*2+1);
    cons_segt(mid+1, hi, pos*2+2);
    segt[pos] = min(segt[pos*2+1], segt[pos*2+2]);
}
int find_min(int qlo, int qhi, int lo, int hi, int pos){
    if(lo>=qlo && hi<=qhi){
        return segt[pos];
    }
    if(lo>qhi || hi<qlo) return INT_MAX;
    int mid = (lo+hi)>>1;
    return min(find_min(qlo, qhi, lo, mid, pos*2+1), find_min(qlo, qhi, mid+1, hi, pos*2+2));
}
int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++) scanf("%d", &input[i]);
    cons_segt(0, N-1, 0);
    int Q, x, y;
    cin>>Q;
    while(Q--){
        scanf("%d%d", &x, &y);
        printf("%d\n", find_min(x, y, 0, N-1, 0));
    }
}
