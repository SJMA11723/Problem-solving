/**
* Author: Mäthgic Crüe
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
typedef vector<vi> vvi;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

struct sparse_table{
    int n, NEUTRO_M, NEUTRO_m;
    vvi ST_M, ST_m;
    vi lg2;

    int fM(int a, int b){return max(a, b);}
    int fm(int a, int b){return min(a, b);}

    sparse_table(int _n, int data[]){
        n = _n;
        NEUTRO_M = INT_MIN;
        NEUTRO_m = INT_MAX;
        lg2.resize(n + 1);
        lg2[1] = 0;
        for(int i = 2; i <= n; ++i) lg2[i] = lg2[i / 2] + 1;
        ST_M.resize(lg2[n] + 1, vi(n, NEUTRO_M));
        ST_m.resize(lg2[n] + 1, vi(n, NEUTRO_m));

        for(int i = 0; i < n; ++i){
           ST_M[0][i] = data[i];
           ST_m[0][i] = data[i];
        }

        for(int k = 1; k <= lg2[n]; ++k){
            int fin = (1 << k) - 1;
            for(int i = 0; i + fin < n; ++i){
                /*
                cout << i + fin << ' ' << i + (1 << (k - 1)) << endl;
                cout << k << ' ' << i << endl;
                cout << sz(ST_M) << ' ' << sz(ST_M[k - 1]) << endl;
                cout << ST_M[k][i] << ' ' << ST_M[k - 1][i] << ' ' << ST_M[k - 1][i + (1 << (k - 1))] << endl;
                cout  << max(ST_M[k - 1][i], ST_M[k - 1][i + (1 << (k - 1))] ) << endl;
                */

                ST_M[k][i] = fM(ST_M[k - 1][i], ST_M[k - 1][i + (1 << (k - 1))]);
                ST_m[k][i] = fm(ST_m[k - 1][i], ST_m[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int MAX(int l, int r){
        if(l > r) return NEUTRO_M;
        int lg = lg2[r - l + 1];
        return fM(ST_M[lg][l], ST_M[lg][r - (1 << lg) + 1]);
    }

    int MIN(int l, int r){
        if(l > r) return NEUTRO_m;
        int lg = lg2[r - l + 1];
        return fm(ST_m[lg][l], ST_m[lg][r - (1 << lg) + 1]);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int &x : arr) cin >> x;

        sparse_table ST(n, arr);

        map<int, int> first, last;
        for(int i = 0; i < n; ++i){
            if(!first.count(arr[i])) first[arr[i]] = i;
            last[arr[i]] = i;
        }

        int M = *max_element(arr, arr + n);
        int m = *min_element(arr, arr + n);

        int ans = M - m;
        sort(arr, arr + n);
        int l = n + 1, r = -1;
        //cout << "Aumenta min:\n";
        for(int i = 0; i + 1 < n; ++i){
            l = min(l, first[arr[i]]);
            r = max(r, last[arr[i]]);
            int x = min(M - m, arr[i + 1] - m);

            //cout << arr[i] << ' ' << l << ' ' << r << ' ' << x << '\n';

            ans = min(ans, max({ST.MAX(0, l - 1), ST.MAX(l, r) + x, ST.MAX(r + 1, n - 1)})
                           - min({ST.MIN(0, l - 1), ST.MIN(l, r) + x, ST.MIN(r + 1, n - 1)}));
            //cout << ans << '\n';
        }

        l = n + 1, r = -1;
        //cout << "Disminuye max:\n";
        for(int i = n - 1; 0 < i; --i){
            l = min(l, first[arr[i]]);
            r = max(r, last[arr[i]]);
            int x = max(m - M, arr[i - 1] - M);

            //cout << arr[i] << ' ' << l << ' ' << r << ' ' << x << '\n';
            ans = min(ans, max({ST.MAX(0, l - 1), ST.MAX(l, r) + x, ST.MAX(r + 1, n - 1)})
                           - min({ST.MIN(0, l - 1), ST.MIN(l, r) + x, ST.MIN(r + 1, n - 1)}));
            //cout << ans << '\n';
        }

        cout << ans << '\n';
    }
}