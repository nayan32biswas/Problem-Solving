#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100009];
int main() {
    int n, d, i, k;
    cin>>n>>d;
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    k=0;
    for(i=d; i<n; i++, k++){
        if(k)cout<<' ';
        printf("%d", arr[i]);
    }
    k=0;
    for(i=0; i<d; i++, k++){
        if(k)cout<<' ';
        printf("%d", arr[i]);
    }cout<<endl;
    return 0;
}
