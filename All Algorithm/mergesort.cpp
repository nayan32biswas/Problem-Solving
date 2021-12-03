#include <bits/stdc++.h>
using namespace std;
int temp[1000];
void merg(int *arr, int lo, int hi) {
    if(lo==hi) return;
    int mid = (lo+hi)/2;
    printf("\t\t\t%d %d\n", lo, hi);
    merg(arr, lo, mid);
    printf("%d %d\n", lo, hi);
    merg(arr, mid+1, hi);
    printf("---> %d %d\n", lo, hi);
    for(int i=lo, k=lo, j=mid+1; k<=hi; k++) {
        if(i == mid+1) temp[k] = arr[j++];
        else if(j == hi+1) temp[k] = arr[i++];
        else if(arr[i] < arr[j]) temp[k] = arr[i++];
        else temp[k] = arr[j++];
     }
     for(int k=lo; k<=hi; k++)arr[k]=temp[k];
     for(int i=0; i<10; i++) cout<<temp[i]<<' ';puts("");
}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, arr[1000];
    cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];
    sort(arr, arr+n);
    for(int i=0; i<n; i++)cout<<arr[i]<<' ';
    cout<<endl;

    return 0;
}
