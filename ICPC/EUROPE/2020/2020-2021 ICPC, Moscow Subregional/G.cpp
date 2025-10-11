#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int arr[k][n];
    for(int j = 0; j < k; ++j){
        for(int i = 0; i < n; ++i) cin >> arr[j][i];
    }

    pair<long double, int> res[n];
    int ans[n], sum = 0;
    for(int i = 0; i < n; ++i){
        long double prom = 0;
        for(int j = 0; j < k; ++j){
            prom += arr[j][i];
        }
        prom /= k;
        ans[i] = prom;
        sum += ans[i];
        res[i] = {prom - ans[i], i};
    }

    sort(res, res + n);
    for(int i = n - 1; 0 <= i; --i){
        if(sum < m){
            sum++;
            ans[res[i].second]++;
        } else if(sum > m){
            sum--;
            ans[res[i].second]++;
        }
    }

    for(int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
}
