#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> arr;
int n, m;
void print()
{
    for (int i = 0; i < n; i++)
    {
        if (i)
            printf(" ");
        printf("%d", arr[i]);
    }
    puts("");
}
void insertFirst(int lo, int hi)
{
    vector<int>temp;
    for(int i=lo; i<=hi; i++)temp.push_back(arr[i]);
    for (int i = lo-1; i>=0; i--){
        arr[hi--] = arr[i];
    }
    for(int i=0; i<temp.size(); i++){
        arr[i] = temp[i];
    }
    // print();
}
void insertLast(int lo, int hi)
{
    vector<int>temp;
    for(int i=lo; i<=hi; i++)temp.push_back(arr[i]);
    for(int i=hi+1; i<n; i++){
        arr[lo++] = arr[i];
    }
    for(int i=0, j=arr.size()-temp.size(); i<temp.size(); i++, j++){
        arr[j] = temp[i];
    }
    // print();
}
void solve()
{
    scanf("%d%d", &n, &m);
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int type, l, r;

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &type, &l, &r);
        // printf("%d %d\n", l, r);
        if (type == 1)
        {
            l--, r--;
            insertFirst(l, r);
        }
        else if (type == 2)
        {
            l--, r--;
            insertLast(l, r);
        }
    }
    cout<<arr[0]-arr[n-1]<<endl;
    print();
}

int main()
{
    solve();
    return 0;
}
