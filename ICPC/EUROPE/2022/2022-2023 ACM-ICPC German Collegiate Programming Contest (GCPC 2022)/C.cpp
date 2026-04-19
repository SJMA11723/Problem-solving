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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(z) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

#define lsb(S) ((S) & -(S))

struct fenwick_tree{
    int n;
    vi BIT;

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

    int sum(int pos){
        int res = 0;
        while(pos){
            res += BIT[pos];
            pos -= lsb(pos);
        }
        return res;
    }

    int sum(int a, int b){
        return sum(b) - sum(a - 1);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, q; cin >> n >> q;

    fenwick_tree BIT(2 * n);

    while(q--){
        char c; cin >> c;
        if(c == '-'){
            int a; cin >> a;
            BIT.add(a, 1);
            BIT.add(a + n, 1);
        } else if(c == '+'){
            int a; cin >> a;
            BIT.add(a, -1);
            BIT.add(a + n, -1);
        } else {
            int a, b; cin >> a >> b;

            if(a > b) swap(a, b);

            if(BIT.sum(b, b) || BIT.sum(a, a)) cout << "impossible\n";
            else if(BIT.sum(a, b) && BIT.sum(b, a + n)) cout << "impossible\n";
            else cout << "possible\n";
        }
    }
}