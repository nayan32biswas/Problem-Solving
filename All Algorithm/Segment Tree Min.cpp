#include <bits/stdc++.h>
using namespace std;
#define MAX INT_MAX
void segTree(int arr[], int segt[], int lo, int hi, int pos){
    if(lo==hi){
        segt[pos] = arr[lo];
        return;
    }
    int mid = (lo+hi)/2;
    int left = pos*2+1, right = pos*2+2;

    segTree(arr, segt, lo, mid, left);
    segTree(arr, segt, mid+1, hi, right);
    segt[pos] = min(segt[left], segt[right]);
    return;
}
int findMin(int segt[], int qlo, int qhi, int lo, int hi, int pos){
    if(qlo<=lo && qhi>=hi){
        return segt[pos];
    }
    if(qlo>hi || qhi<lo) return MAX;
    int mid = (lo+hi)/2;
    int left = pos*2+1, right = pos*2+2;

    return min(findMin(segt, qlo, qhi, lo, mid, left), findMin(segt, qlo, qhi, mid+1, hi, right));
}
void update(int segt[], int ppp, int up, int lo, int hi, int pos){
    if(lo==hi){
        segt[pos] = up;
        return;
    }
    int mid = (lo+hi)/2;
    int left = pos*2+1, right = pos*2+2;

    if(ppp<=mid) update(segt, ppp, up, lo, mid, left);
    else update(segt, ppp, up, mid+1, hi, right);
    segt[pos] = min(segt[left], segt[right]);
    return;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int Size, arr[50], segt[100];
    cin>>Size;
    for(int i=0; i<Size; i++){
        cin>>arr[i];
    }
    segTree(arr, segt, 0, Size-1, 0);
    for(int i=0; i<13; i++) printf("%4d", segt[i]);puts("");
    int Q, lo, hi, up, ppp;
    cin>>Q;
    while(Q--){
        cin>>lo>>hi;
        cout<<lo<<' '<<hi<<endl;
        lo--, hi--;
        cout<<findMin( segt, lo,  hi,  0,  Size-1,  0)<<endl;
    }
    cin>>Q;
    while(Q--){
        cin>>ppp>>up;
        cout<<ppp<<' '<<up<<endl;
        ppp--;
        update(segt, ppp, up, 0, Size-1, 0);
        for(int i=0; i<13; i++) printf("%4d", segt[i]);puts("");
    }
    cin>>Q;
    while(Q--){
        cin>>lo>>hi;
        cout<<lo<<' '<<hi<<endl;
        lo--, hi--;
        cout<<findMin( segt, lo,  hi,  0,  Size-1,  0)<<endl;
    }
    return 0;
}
