#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first 
#define se second  
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

#define lsb(n) ((n) & -(n))

struct fenwick_tree{
    int n;
    vll BIT;

    fenwick_tree(int _n){
        n = _n;
        BIT.resize(n + 1);
    }

    void add(int pos, int x){
        while(pos <= n){
            BIT[pos] += x;
            pos += lsb(pos);
        }
    }

    ll pref(int pos){
        ll res = 0;
        while(pos){
            res += BIT[pos];
            pos -= lsb(pos);
        }
        return res;
    }

    ll suff(int pos){
        return pref(n) - pref(pos - 1);
    }

    void reset(){
        for(ll &x : BIT) x = 0;
    }

    int val(int pos){
        return pref(pos) - pref(pos - 1);
    }

    void swap(int i, int j){
        int x = val(i);
        int y = val(i + 1);
        add(i, y - x);
        add(i + 1, x - y);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q; cin >> n >> q;

    int arr[n + 1];
    //int mayores_der[n + 1] = {};
    fenwick_tree freq(n), mayor_izq(n), menor_izq(n);
    for(int i = 1; i <= n; ++i){
        cin >> arr[i];
        //mayores_der[i] = i - 1 - freq.pref(arr[i]);
        menor_izq.add(i, freq.pref(arr[i] - 1));
        mayor_izq.add(i, freq.suff(arr[i] + 1));
        freq.add(arr[i], 1);
    }

    fenwick_tree menor_der(n), mayor_der(n);
    freq.reset();
    for(int i = n; 0 < i; --i){
        menor_der.add(i, freq.pref(arr[i] - 1));
        mayor_der.add(i, freq.suff(arr[i] + 1));
        freq.add(arr[i], 1);
    }

    ll ans = mayor_izq.pref(n);
    for(int i = 1; i <= n; ++i) ans += i - arr[i];

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i; cin >> i;
            if(arr[i] < arr[i + 1]){
                ans++;
                mayor_der.add(i, -1);
                menor_izq.add(i + 1, -1);

                menor_der.swap(i, i + 1);
                mayor_der.swap(i, i + 1);
                menor_izq.swap(i, i + 1);
                mayor_izq.swap(i, i + 1);
                
                menor_der.add(i, 1);
                mayor_izq.add(i + 1, 1);
            } else {
                ans--;
                menor_der.add(i, -1);
                mayor_izq.add(i + 1, -1);

                menor_der.swap(i, i + 1);
                mayor_der.swap(i, i + 1);
                menor_izq.swap(i, i + 1);
                mayor_izq.swap(i, i + 1);

                mayor_der.add(i, 1);
                menor_izq.add(i + 1, 1);
            }

            swap(arr[i], arr[i + 1]);
        } else {
            int k; cin >> k;

            ll new_inv = mayor_izq.pref(k) + menor_der.suff(k + 1);
            new_inv += mayor_der.pref(k) - menor_izq.pref(k);

            cout << ans - mayor_izq.pref(n) + new_inv << '\n';
        }
    }
}