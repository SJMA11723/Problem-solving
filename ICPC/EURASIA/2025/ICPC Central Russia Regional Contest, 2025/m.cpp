#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    set<int> pending;
    for(int i = 0; i < n; ++i) pending.insert(i);
    while(k--){
        int idx; cin >> idx;
        auto it = pending.lower_bound(idx);
        int R = it == pending.end() ? INT_MAX : *it - idx;
        int L = INT_MAX;
        if(it != pending.begin()){
            it--;
            L = idx - *it;
            it++;
        }
        if(L <= R) it--;
        cout << *it << '\n';
        pending.erase(it);
    }
}