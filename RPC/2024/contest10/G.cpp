#include <bits/stdc++.h>

using namespace std;

struct speedup{
    int x, m, d;
    const bool operator<(const speedup &b)const{
        return x < b.x;
    }
};

int n, L;
long double dp[1001];
vector<speedup> arr;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> L;
    arr.resize(n);
    for(speedup &s : arr) cin >> s.x >> s.m >> s.d;
    sort(arr.begin(), arr.end());

    long double ans = L;

    for(int i = 0; i < n; ++i){
        dp[i] = arr[i].x;
        for(int j = 0; j < i; ++j){
            if(arr[j].x + arr[j].m * arr[j].d <= arr[i].x) dp[i] = min(dp[i], dp[j] + arr[j].d + arr[i].x - arr[j].x - arr[j].m * arr[j].d);
        }

        if(arr[i].x + arr[i].m * arr[i].d <= L) ans = min(ans, dp[i] + arr[i].d + L - arr[i].x - arr[i].m * arr[i].d);
        else ans = min(ans, dp[i] + (long double)(L - arr[i].x) / arr[i].m);
    }

    cout << fixed << setprecision(7) << ans << '\n';
}
