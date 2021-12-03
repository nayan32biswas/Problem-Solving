#include <bits/stdc++.h>
using namespace std;
void heapPermutation(vector<int> &arr, int size, int n)
{
    if (size == 1)
    {
        for (auto it : arr)
            printf("%d ", it);
        puts("");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        heapPermutation(arr, size - 1, n);
        if (size % 2 == 1)
            swap(arr[0], arr[size - 1]);
        else
            swap(arr[i], arr[size - 1]);
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(1), arr.push_back(2);
    arr.push_back(3), arr.push_back(4);
    arr.push_back(5), arr.push_back(6);
    int size = arr.size();
    heapPermutation(arr, size, size);
}
