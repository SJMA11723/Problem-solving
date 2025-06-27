#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;

    int mini[n + 1];
    mini[n] = INT_MAX;
    mini[n - 1] = arr[n - 1];
    for(int i = n - 2; 0 <= i; --i) mini[i] = min(arr[i], mini[i + 1]);

    vector<int> ans;
    int maxi = INT_MIN;
    for(int i = 0; i < n; ++i){
        if(maxi < arr[i] && arr[i] < mini[i + 1]) ans.push_back(arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int N = min((int)ans.size(), 100);
    cout << ans.size() << " \n"[ans.empty()];
    for(int i = 0; i < N; ++i) cout << ans[i] << " \n"[i + 1 == N];
}
