#include <bits/stdc++.h>
using namespace std;
#define Size 20
int sum[Size*4];
int arr[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void make(int At, int lo, int hi){
    sum[At]=0;
    if(lo==hi){
        sum[At]=arr[lo];
        return;
    }

    int mid=(lo+hi)>>1;
    make(At*2, lo, mid);
    make((At*2)+1, mid+1, hi);
    sum[At]=sum[At*2]+sum[(At*2)+1];
}
int query(int At, int lo, int hi, int l, int r){
    if(r<lo||hi<l) return 0;
    if(l<=lo && hi<=r) return sum[At];

    int mid = (lo+hi)>>1;
    int x = query((At*2), lo, mid, l, r);
    int y = query((At*2)+1, mid+1, hi, l, r);
    return x+y;
}
void update(int At, int lo, int hi, int pos, int incr){
    if(lo==hi){
        sum[At] += incr;
        return;
    }
    int mid=(lo+hi)>>1;
    if(pos<=mid) update(At*2, lo, mid, pos, incr);
    else update(At*2+1, mid+1, hi, pos, incr);
    sum[At]=sum[At*2]+sum[(At*2)+1];
}
int main()
{
    make(1, 1, 11);
    int n=10;
    for(int i=0; i<n*3; i++) cout<<sum[i]<<' ';puts("");
    cout<<query(1, 1, n, 1, 10)<<endl;
    update(1, 1, n, 3, -1);
    for(int i=0; i<n*3; i++) cout<<sum[i]<<' ';puts("");
    cout<<query(1, 1, n, 1, 10)<<endl;

}
