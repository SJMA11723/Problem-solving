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
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int arr[n];
        for(int &x : arr) cin >> x;
        
        int ans = 0;
        reverse(arr, arr + n);
        for(int i = 0; i < n; ++i){
            int ops = 0, cur_max = arr[i];
            int tmp_first = arr[i];
            // 100 5 6 7 8

            ans = max(ans, arr[i]);
            int j;
            for(j = i + 1; j < n; ++j){
                if(cur_max < arr[j]){
                    // intentamos aumentar tmp_first hasta que cur_max = arr[j]
                    if(!i) break; // arr[i] es el ultimo y no puede ser aumentado
                    if(arr[i - 1] < tmp_first) break; // no se cumple la condicion para usar la operacion

                    int needed = arr[j] - cur_max;
                    // si todavia podemos aumentar tmp_first en lo que necesitamos
                    // y nos sobran operaciones para realizarlo
                    if(needed <= arr[i - 1] - tmp_first + 1 && ops + 1ll * (j - i) * needed <= k){
                        tmp_first += needed;
                        cur_max = arr[j];
                        ops += (j - i) * needed;
                    }
                }

                if(ops + cur_max + 1 - arr[j] > k) break;

                cur_max++;
                ops += cur_max - arr[j];
                ans = max(ans, cur_max);
            }

            if(i && tmp_first <= arr[i - 1]) cur_max += min(arr[i - 1] - tmp_first + 1, (k - ops) / (j - i));
            ans = max(ans, cur_max);
        }
        cout << ans << '\n';
    }
}