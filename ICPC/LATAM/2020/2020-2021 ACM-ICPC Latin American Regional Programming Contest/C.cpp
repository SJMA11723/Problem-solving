#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    int target = 0;
    for(int &x : arr){
        cin >> x;
        target += x;
    }

    target /= n;

    int64_t ans1 = 0, ans2 = 0;

    int arr2[n];
    memcpy(arr2, arr, sizeof(arr));

    int carry = 0;
    for(int i = 0; i < 3 * n; ++i){
        ans1 += carry;

        int idx = i % n;

        if(arr[idx] >= target){
            carry += arr[idx] - target;
            arr[idx] = target;
        } else {
            int cnt = min(target - arr[idx], carry);
            arr[idx] += cnt;
            carry -= cnt;
        }
    }

    reverse(arr2, arr2 + n);
    carry = 0;
    for(int i = 0; i < 3 * n; ++i){
        ans2 += carry;

        int idx = i % n;

        if(arr2[idx] >= target){
            carry += arr2[idx] - target;
            arr2[idx] = target;
        } else {
            int cnt = min(target - arr2[idx], carry);
            arr2[idx] += cnt;
            carry -= cnt;
        }
    }

    cout << min(ans1, ans2) << '\n';
}



