#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<long long> llvec;
#define Size 200005
int pastPos, left;
void Find(llvec AAA, vec aaa, vec hhh, int n, int q, int pos) {
    int power = kkk[pos];
    long long left = AAA[n-1]-AAA[pastPos];
    if(pastPos==0) left = A[n-1];
    if(power>=left){
        printf("%d\n", n-pastPos);
        pastPos=0;
        left = 0;
        return;
    }
    power -= left;
    lower = AAA+lower_bound(AAA.begin(), AAA.end(), AAA[pastPos]+power)-1;
    lower = max(lower, pastPos);


    for(int i=lower; i<n; i++){
        if(aaa[i]<power){
            power -= aaa[i];
        }
    }

}
int main() {
    int n, q;
    long long AAA=0;
    scanf("%d%d", &n, &q);

    vector<int>aaa(n), kkk(q);
    vector<long long>AAA(n);

    scanf("%d", &aaa[0]);
    AAA[0] = aaa[0];
    for(int i=1; i<n; i++) {
        scanf("%d", &aaa[i]);
        AAA[i] = AAA[i-1]+aaa[i];
    }
    for(int i=0; i<q; i++) {
        scanf("%d", &kkk[i]);
    }
    for(int i=0; i<q; i++) {
        Find(AAA, aaa, hhh, n, q, i);
    }
    return 0;
}
