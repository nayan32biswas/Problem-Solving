#include <bits/stdc++.h>
using namespace std;
void Erase(int pos, vector<int>&vec) {
    vec.erase(vec.begin()+pos, vec.begin()+pos+1);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int>arr(n), arr1(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    for(int i=0; i<n; i++)
        scanf("%d", &arr1[i]);
    for(int i=0, pos=0; i<n; i++, pos++) {
        int sum = 0;
        int num = arr1[i];
        for(int j = pos; j>=0; j--) {
            if(arr[j]>num) {
                sum += num;
                arr[j] -= num;
            } else if(arr[j]==num) {
                sum += num;
                Erase(j, arr);
                pos--;
            } else {
                sum += arr[j];
                Erase(j, arr);
                pos--;
            }
        }
        printf("%d ", sum);
    }
    return 0;
}
