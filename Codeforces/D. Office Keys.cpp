#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int people[1003], key[20009];
int Pos(int arr[], int num, int k){
    int start=0, End=k-1, mid;
    if(num>arr[k-1]) return k-1;
    if(num<arr[0]) return 0;
    while(start<=End){
        mid = (start+End)/2;
        if(arr[mid]==num) return mid;
        else if(num<arr[mid]) End = mid-1;
        else start = mid+1;
    }
    return mid;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, office, i, pos, num, temp, temp1;
    unsigned long long ans, Max=0;
    scanf("%d%d%d", &n, &k, &office);
    for(i=0; i<n; i++)scanf("%d", &people[i]);
    for(i=0; i<k; i++)scanf("%d", &key[i]);
    sort(key, key+k);
    for(i=0; i<n; i++){
        ans = 1e15;
        num = people[i];
        pos = Pos(num, k);
        pos-=3;
        pos = max(key, pos, 0);
        for(int j=pos; j<pos+10 && j<k; j++){
            ans = min(ans, (ull)abs(key[j]-num)+(ull)abs(key[j]-office));

        }
        Max = max(ans, Max);
    }
    cout<<Max<<endl;
    return 0;
}
