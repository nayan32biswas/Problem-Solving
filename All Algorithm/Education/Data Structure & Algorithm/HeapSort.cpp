#include <bits/stdc++.h>
using namespace std;
#define Size 8
int T, C;
int arr[Size];
int Left(int i);
int Right(int i);
int Parent(int i);
void calculate();
void print(int arr[], int N);
void HeapSort(int A[], int heap_size);
void Buld_Max_Heap(int A[], int heap_size);
void Max_Heapify(int A[], int i, int heap_size);

int main() {
    for(int i=0; i<Size; i++)
        arr[i] = i;
    HeapSort(arr, Size);
    calculate();
    reverse(arr, arr+Size);
    calculate();
    reverse(arr, arr+Size);
    calculate();
    calculate();
    calculate();
    printf("Average time for heap sort %d\n", T/C);
    return 0;
}
void Max_Heapify(int A[], int i, int heap_size) {
    int l = Left(i), r = Right(i), largest;
    if(l<=heap_size && A[l]>A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if(r<=heap_size && A[r]>A[largest]) {
        largest = r;
    }
    if(largest != i) {
        swap(A[i], A[largest]);
        Max_Heapify(A, largest, heap_size);
    }
}



void HeapSort(int A[], int heap_size) {
    heap_size--;
    Buld_Max_Heap(A, heap_size);
    for(int i=heap_size; i>0; i--) {
        swap(A[0], A[i]);
        heap_size--;
        Max_Heapify(A, 0, heap_size);
    }
}
void Buld_Max_Heap(int A[], int heap_size) {
    for(int i=heap_size/2; i>=0; i--) {
        Max_Heapify(A, i, heap_size);
    }
}
void calculate() {
    int time = clock();
    HeapSort(arr, Size);
    print(arr, Size);
    printf("Time is %d\n", clock()-time);
    T += clock()-time;
    C++;
}
int Left(int i) {
    return i<<1;
}
int Right(int i) {
    return (i<<1)+1;
}
int Parent(int i) {
    return i>>1;
}
void print(int arr[], int N) {
    for(int i=0; i<N; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}
