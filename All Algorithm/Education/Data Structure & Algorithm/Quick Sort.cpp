#include <bits/stdc++.h>
using namespace std;
int Size;
void print(int n, int A[]);
void quickSort(int A[], int p, int r);
int Partition(int A[], int p, int r, int pivot);
int PARTITION(int A[], int left, int right, int pivot);
int main() {
    int arr[] = {3, 6, 2, 8, 7, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    Size = n;
    quickSort(arr, 0, n-1);
    print(n, arr);
    return 0;
}
void quickSort(int A[], int p, int r) {
    if(p<r) {
        int pivot = A[(p+r)/2];
        int q = PARTITION(A, p, r, pivot);
        //print(Size, A);
        quickSort(A, p, q-1);
        quickSort(A, q, r);
    }
}
int Partition(int A[], int p, int r, int pivot) {
    int i=p-1;
    for(int j=p; j<r; j++) {
        if(A[j]<=pivot) {
            swap(A[++i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}
int PARTITION(int A[], int left, int right, int pivot) {
    while(left <= right) {
        while(A[left] < pivot)
            left++;
        while(A[right] > pivot)
            right--;
        if(left <= right) {
            swap(A[left], A[right]);
            left++, right--;
        }
    }
    return left;
}
void print(int n, int A[]) {
    for(int i=0; i<n; i++)
        printf("%d ", A[i]);
    puts("");
}
