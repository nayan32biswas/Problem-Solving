#include <bits/stdc++.h>
using namespace std;
void Insertion(int A[], int n){
    for(int j=1; j<n; j++){
        int key = A[j];
        int i = j-1;
        while(i>=0 && A[i]>key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}
int main()
{
    int arr[] = {7, 8, 1, 6, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    Insertion(arr, n);
    for(int i=0; i<n; i++)cout<<arr[i]<<' '; puts("");
    return 0;
}
