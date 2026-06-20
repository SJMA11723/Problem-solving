/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;
        sort(arr, arr + n);
        int ans = INT_MAX;
        int cur_val = -1;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(cur_val != arr[i]){
                ans = min(ans, max(cnt, n - i));
                cur_val = arr[i];
                cnt = i;
            }

            if(i == n - 1) ans = min(ans, cnt);
        }
        if(*min_element(arr, arr + n) == *max_element(arr, arr + n)) ans = 0;
        cout << ans << '\n';
    }
}