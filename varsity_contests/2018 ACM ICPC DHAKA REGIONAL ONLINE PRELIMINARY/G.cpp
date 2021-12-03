#include<bits/stdc++.h>
using namespace std;
vector<int>arr, gcd;
void ccountSubsets(int n, int m) {
    map<int, int> freq;
    map<int, int> subsets;
    int arrMax = 0;
    for (int i=0; i<n; i++) {
        arrMax = max(arrMax, arr[i]);
        freq[arr[i]]++;
    }
    for (int i=arrMax; i>=1; i--) {
        int sub = 0;
        int add = freq[i];
        for (int j = 2; j*i <= arrMax; j++) {
            add += freq[j*i];
            sub += subsets[j*i];
        }
        subsets[i] = (1<<add) - 1 - sub;
    }
    for (int i=0; i<m; i++){
        puts(subsets[gcd[i]] ? "Y" : "N");
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    int test, N, Q;

    scanf("%d", &N);
    arr.resize(N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    int K, low;

    scanf("%d", &Q);
    for(int t=1; t<=Q; t++) {
        scanf("%d", &K);
        gcd.push_back(K);

    }
    //sort(gcd.begin(), gcd.end());
    ccountSubsets(arr.size(), gcd.size());
    cout<<clock()<<endl;
    return 0;
}
