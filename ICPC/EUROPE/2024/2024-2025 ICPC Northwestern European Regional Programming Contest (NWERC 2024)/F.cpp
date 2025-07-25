#/**
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
    int n, q; cin >> n >> q;
    stack<int> st;
    int nxt[n], arr[n];
    memset(nxt, -1, sizeof(nxt));
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        while(st.size() && arr[st.top()] < arr[i]){
            nxt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(st.size()) st.pop();

    int ans[n] = {};
    while(q--){
        char c; cin >> c;
        if(c == '+'){
            vector<int> upd;
            int l, x; cin >> l >> x;
            l--;
            if(ans[l] + x < arr[l]){
                ans[l] += x;
                continue;
            }
            if(ans[l] == arr[l]){
                upd.pb(l);
                l = nxt[l];
            }

            int new_nxt = -1;
            while(l != -1 && x){
                int k = min(x, arr[l] - ans[l]);
                ans[l] += k;
                x -= k;
                if(ans[l] == arr[l]){
                    upd.pb(l);
                    l = nxt[l];
                }
                
                new_nxt = l;
            }
            for(int i : upd) nxt[i] = new_nxt;
        } else {
            int l; cin >> l;
            l--;
            cout << ans[l] << '\n';
        }
    }
}