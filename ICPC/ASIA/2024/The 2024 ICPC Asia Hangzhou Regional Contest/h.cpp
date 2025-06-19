#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back

int len(pii &p){
    return p.se - p.fi + 1;
}

bool comp(pii &a, pii &b){
    return len(a) > len(b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        pii arr[k];
        for(pii &p : arr) cin >> p.fi >> p.se;

        if(n == 1){
            cout << "0\n";
            continue;
        }

        if(k == 1){
            cout << "0 ";
            for(int i = 2; i <= n; ++i) cout << i - 1 << " \n"[i == n];
            continue;
        }

        sort(arr, arr + k, comp);
        
        if(len(arr[0]) == len(arr[1]) && len(arr[0]) - len(arr[k - 1]) <= 1){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        int ans[n + 1] = {};
        for(int i = 0; i < k; ++i){
            if(i) ans[arr[i].fi] = arr[0].fi;
            if(i + 1 == k) ans[arr[i].fi] = arr[0].se - len(arr[i]);

            for(int j = arr[i].fi + 1; j <= arr[i].se; ++j) ans[j] = j - 1;
        }

        for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
    }
}