#include <bits/stdc++.h>
using namespace std;
void bubble(int arr[], int n)
{
   for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(arr[j], arr[j+1]);
}
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("unsorted array: ");
    for(int i=0; i<n; i++)printf("%d ", arr[i]);
    puts("");
    bubble(arr, n);
    printf("sorted array: ");
    for(int i=0; i<n; i++)printf("%d ", arr[i]);
    puts("");
    return 0;
}