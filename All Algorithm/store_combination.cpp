#include <bits/stdc++.h>
using namespace std;
void findNumbers(vector<int>& arr, int sum, vector<vector<int> >& res, vector<int>& r, int i) {
    if(sum < 0) return;
    if(sum == 0) {
        res.push_back(r);
        return;
    }
    while (i < arr.size() && sum - arr[i] >= 0) {
        r.push_back(arr[i]);
        findNumbers(arr, sum - arr[i], res, r, i);
        i++;
        r.pop_back();
    }
}
void combinationSum(vector<int>& arr, int sum) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<int> r;
    vector<vector<int> > res;
    int start = clock();
    findNumbers(arr, sum, res, r, 0);
    if (res.size() == 0) cout << "Empty n";
    else for(int i = 0; i < res.size(); i++)if (res[i].size() > 0) {
            for(auto it : res[i])cout << it << " ";
            printf("\n");
        }

}
int main() {
    int myints[] = {2, 4, 2, 8};
    vector<int> arr;
    //arr.assign(myints, myints+(sizeof(myints)/4));
    for(int i=1; i<10; i++) arr.push_back(i);
    int sum = 6;
    combinationSum(arr, i);
    return 0;
}
