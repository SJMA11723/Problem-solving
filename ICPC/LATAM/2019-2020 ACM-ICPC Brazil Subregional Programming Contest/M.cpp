#include <bits/stdc++.h>

using namespace std;

bool check(int n, int arr[], const int time, const int c, const int t){
    int cnt = 1, sum = 0;
    for(int i = 0; i < n; ++i){
        if(sum + arr[i] <= 1ll * t * time) sum += arr[i];
        else if(arr[i] <= 1ll * t * time){
            sum = arr[i];
            cnt++;
        } else return false;
    }
    return cnt <= c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c, t;
    cin >> n >> c >> t;
    int arr[n];
    for(int &x : arr) cin >> x;

    int l = 0, r = INT_MAX;
    while(l < r){
        int mid = l + (r - l) / 2;
        if(check(n, arr, mid, c, t)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
