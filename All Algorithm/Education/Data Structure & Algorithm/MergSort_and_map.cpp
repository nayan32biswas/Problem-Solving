#include <bits/stdc++.h>
using namespace std;
#define Size 1000000
#define INF INT_MAX

int L[(Size>>1)+1], R[(Size>>1)+1];
int arr[Size], M, D, T, T1;

void Merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);
void insartion(int A[], int lo, int hi);
void mergeTime() {
    int time = clock();
    mergeSort(arr, 0, Size-1);
    printf("merge sort time: %d\n", clock()-time);
    M += clock()-time;
    T++;
}
void defaultTime() {
    int time = clock();
    sort(arr, arr+Size);
    printf("default sort time: %d\n", clock()-time);
    D += clock()-time;
    T1++;
}
void print(){
    for(int i=0; i<Size; i++)
        printf("%d ", arr[i]);
    puts("");
}

int main() {
    for(int i=0; i<Size; i++)
        arr[i] = i;

    mergeTime();
    reverse(arr, arr+Size);
    mergeTime();
    puts("");

    defaultTime();
    reverse(arr, arr+Size);
    defaultTime();
    puts("");

    mergeTime();
    reverse(arr, arr+Size);
    mergeTime();
    puts("");

    mergeTime();
    reverse(arr, arr+Size);
    mergeTime();
    puts("");

    printf("Average time for merge sort %d\n", M/T);
    //printf("for default sort %d\n", D/T1);
}
void mergeSort(int A[], int p, int r) {
    if(r-p<32) insartion(A, p, r);
    else{
        int q = (p+r)>>1;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        Merge(A, p, q, r);
    }
}
void insartion(int A[], int lo, int hi){
    for(int i=lo+1, key, j; i<=hi; i++){
        key = A[i];
        j = i-1;
        while(j>=lo && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;

    }
}
void Merge(int A[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int i, j, k;
    for(i=0; i<n1; i++)
        L[i] = A[p+i];
    for(j=0; j<n2; j++)
        R[j] = A[q+j+1];
    L[n1] = INF;
    R[n2] = INF;
    for(i=0, j=0, k=p; k<=r; k++) {
        if(L[i]<=R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

