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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());

uniform_int_distribution<ll> distr(1, 1e18);

const int MOD = 1e9 + 7;

struct prefix{
    vll arr;

    prefix(int n){
        arr.resize(n);
    }

    void add(int pos, int x){
        arr[pos] += x;
    }

    void precalc(){
        for(int i = 1; i < sz(arr); ++i)
            arr[i] += arr[i - 1];
    }

    int query(int pos){
        return arr[pos];
    }
};

vi nums;
int idx(int x){
    return lower_bound(all(nums), x) - nums.begin();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, q; cin >> n >> k >> q;

    int l[q], r[q];
    for(int i = 0; i < q; ++i){
        cin >> l[i] >> l[i] >> r[i];
        nums.pb(l[i]);
        nums.pb(r[i]);
        nums.pb(r[i] + 1);
    }
    
    {
        sort(all(nums));
        auto it = unique(all(nums));
        nums.resize(it - nums.begin() + 1);
    }

    int N = nums.size();
    prefix acc(N + 1);
    for(int i = 0; i < q; ++i){
        acc.add(idx(l[i]), 1);
        acc.add(idx(r[i] + 1), -1);
    }
    acc.precalc();


    string ans;
    prefix acc2(N + 1);
    for(int i = 0; i < q; ++i){
        if(acc.query(idx(r[i])) == n){
            ans += "1";
            acc2.add(idx(l[i]), 1);
            acc2.add(idx(r[i] + 1), -1);
        } else {
            ans += "0";
        }
    }
    acc2.precalc();

    bool ok = true;
    for(int i = 0; i < q; ++i){
        if(acc2.query(idx(l[i])) > k || acc2.query(idx(r[i])) > k){
            ok = false;
            break;
        }
    }

    if(ok) cout << ans << '\n';
    else cout << "impossible\n";
}