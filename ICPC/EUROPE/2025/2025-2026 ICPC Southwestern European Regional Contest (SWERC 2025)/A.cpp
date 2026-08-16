#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
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

const bool deb = 0;
#define DEBUG if(deb)

const int MOD = 1e9 + 7;

bool check(int n, vi cnt, int ops, int k, int MAX){
    set<int> pos;
    for(int i = 1; i <= MAX + n; ++i) pos.insert(i);

    auto cur_pos = pos.find(MAX);
    for(int i = MAX; i; --i){
        int freq = cnt[i];
        int val = i;
        if(freq == 1){
            cur_pos = pos.erase(cur_pos);
            if(cur_pos != pos.begin() && sz(pos)) cur_pos--;
            continue;
        }

        auto nxt = cur_pos;
        if(cur_pos != pos.begin()) cur_pos--;
        for(int j = 0; j < ops && freq > 1; ++j){
            nxt = pos.erase(nxt);
            if(ops - j < *nxt - val){
                pos.insert(val + ops - j);
                //nxt = val + ops - j;
                nxt--;
                j = ops - 1;
            } else {
                freq--;
                j += *nxt - val - 1;
            }

            val = *nxt;
        }

        if(freq == 1) pos.erase(nxt);
        if(freq > k) return 0;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vi cnt(3 * n + 1);
        int maxi = 0;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cnt[x]++;
            maxi = max(maxi, x);
        }

        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(n, cnt, mid, k, maxi)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
}