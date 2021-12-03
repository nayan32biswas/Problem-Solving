#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int N){
    for(int i=0; i<N; i++) cout<<arr[i]<<" ";
    puts("");
}
void insert(int arr[], int &N){

    int pos, num;
    printf("For insert enter position : ");
    scanf("%d", &pos);
    printf("Enter position : ");
    scanf("%d", &num);

    pos--;
    for(int i=N; i>pos; i--)arr[i] = arr[i-1];
    arr[pos] = num;
    N++;
}
void Delet(int arr[], int &N){
    int pos;
    printf("For insert enter position : ");
    scanf("%d", &pos);
    pos--, N--;
    for(; pos<N; pos++) arr[pos] = arr[pos+1];
}
int main()
{
    int N;
    int arr[1000];
    printf("input array size : ");
    cin>>N;
    printf("input value\n");
    for(int i=0; i<N; i++) cin>>arr[i];

    insert(arr, N);
    print(arr, N);
    Delet(arr, N);
    print(arr, N);
    return 0;
}
