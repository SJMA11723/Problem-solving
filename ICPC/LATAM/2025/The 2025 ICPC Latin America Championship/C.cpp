#include <bits/stdc++.h>

using namespace std;

bool check(int n, int c, int arr[], pair<int, int> arr2[], int k){
    int diff[n + 1] = {};

    for(int i = k; i < n; ++i) diff[ arr2[i].second ]++, diff[ min(n, arr2[i].second + c + 1) ]--;

    int acc = 0, mini = INT_MAX;
    for(int i = 0; i < n; ++i){
        acc += diff[i];
        if(!acc && i >= c) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n; cin >> c >> n;
    int arr[n];
    pair<int, int> arr2[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        arr2[i] = {arr[i], i};
    }
    sort(arr2, arr2 + n);

    int l = 0, r = n;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(n, c, arr, arr2, mid)) l = mid + 1;
        else r = mid;
    }
    cout << arr2[l - 1].first << '\n';
}
