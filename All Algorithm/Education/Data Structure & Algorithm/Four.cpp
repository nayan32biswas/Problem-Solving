#include <bits/stdc++.h>
using namespace std;
int N, arr[1000];
void show(){
    for(int i=0; i<N; i++) cout<<arr[i]<<" ";cout<<endl;
}
void Insert(){
    int pos;
    printf("Input your position: ");
    cin>>pos;
    pos--;
    for(int i=N; i>pos; i--) arr[i] = arr[i-1];
    printf("Input your number: ");
    cin>>arr[pos];
    N++;
}
void Delete(){
    int pos;
    printf("Input your position: ");
    cin>>pos;
    N--, pos--;
    for(int i=pos; i<N; i++) arr[i] = arr[i+1];
}
bool Bainary_Search(int num){
    int start=0, End = N-1, mid;
    while(start<=End){
        mid = (start+End)>>1;
        if(arr[mid]<num) start = mid+1;
        else End = mid-1;
        if(arr[mid]==num) return true;
    }
    return false;
}
void bubble_sort(){
    for(int i=0; i<N-1; i++){
        bool ck = true;
        for(int j=0; j<N-i-1; j++){
            if(arr[j]>arr[j+1])swap(arr[j], arr[j+1]), ck = false;
        }
        if(ck) return;
    }
}
int main()
{
    int num;
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    bubble_sort();
    show();
    while(cin>>num && num){
        if(Bainary_Search(num)) puts("Successful");
        else puts("Not Successful");
    }
    return false;
}
