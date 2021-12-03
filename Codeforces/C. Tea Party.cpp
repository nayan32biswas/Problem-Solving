#include <bits/stdc++.h>
using namespace std;
struct stor{int a, b, c;}arr[109];

void SORTa(int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arr[i].a>arr[j].a)swap(arr[i], arr[j]);
        }
    }
}

void SORTb(int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arr[i].b<arr[j].b)swap(arr[i], arr[j]);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, w, i, j, wat;
    scanf("%d%d", &n, &w);
    for(i=0; i<n; arr[i].b=i, i++) scanf("%d", &arr[i].a),arr[i].c=arr[i].a;

    SORTa(n);
    for(i=0; i<n; i++){
        wat = (arr[i].a+1)/2;
        arr[i].a = wat;
        w-=wat;
    }
    if(w<0) return puts("-1");
    while(w>0){
        for(i=0; i<n && w>0; i++){
            wat = (arr[i].c-arr[i].a+1)/2;
            w-=wat;
            if(w>=0)arr[i].a+=wat;
            else{
                arr[i].a+=(w+wat);
                w = 0;
            }
        }
    }
    SORTb(n);
    for(i=0; i<n; i++){
        if(i) printf(" ");
        printf("%d", arr[i].a);
    }cout<<endl;
    return 0;
}
/// for(i=0; i<n; i++)cout<<arr[i].a<<' '; cout<<endl;
