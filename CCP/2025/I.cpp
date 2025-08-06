#include <bits/stdc++.h>

using namespace std;

struct cosa{
    int a, e, c;
    bool operator<(cosa &b){
        return make_tuple(a, e, c) < make_tuple(b.a, b.e, b.c);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    cosa arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i].a >> arr[i].e >> arr[i].c;
    }
    sort(arr, arr + n);
    int dp[n], ans = 0;
    for(int i = 0; i < n; ++i){
        dp[i] = 0;
        for(int j = 0; j < i; ++j){
            if(arr[j].a < arr[i].a && arr[j].e < arr[i].e && arr[j].c < arr[i].c){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}