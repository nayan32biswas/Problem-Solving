#include <bits/stdc++.h>
using namespace std;
void print(int A[], int n){
    for(int i=0; i<n; i++) cout<<A[i]<<" "; puts("");
}
void Count_Sort(int A[], int n, int k){
    int C[k+1], B[n+1];
    cout<<n<<" "<<k<<endl;
    memset(C, 0, sizeof(C));
    for(int j=0; j<n; j++){
        C[A[j]]++;
    }
    for(int i=1; i<=k; i++){
        C[i] = C[i]+C[i-1];
    }
    for(int j=n-1; j>=0; j--){
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for(int i=0; i<n; i++)
        A[i] = B[i+1];
}
int main()
{
    int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int n = sizeof(A)/sizeof(A[0]);
    int k=-INT_MAX;
    for(int i=0; i<n; i++){
        k = max(k, A[i]);
    }
    Count_Sort(A, n, k);
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    puts("");
    return 0;
}
