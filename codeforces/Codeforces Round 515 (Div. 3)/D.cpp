/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n,int arr[], int m, int k, int mid){
    int cnt = 1, sum = 0;
    for(int i = mid; i < n; ++i){
        if(sum + arr[i] > k){
            sum = 0;
            cnt++;
        }
        sum += arr[i];
    }
    return cnt <= m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int arr[n];
    for(int &x : arr) cin >> x;

    int l = 0, r = n;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(n, arr, m, k, mid)) r = mid;
        else l = mid + 1;
    }
    cout << n - l << '\n';
}
