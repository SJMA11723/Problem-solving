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
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);
const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;

    int prefa[n];
    int prefb[n];
    prefa[0] = s[0] == '4';
    prefb[0] = s[0] == '8';
    for(int i = 1; i < n; i++){
        
        prefa[i] = prefa[i-1];
        prefb[i] = prefb[i-1];
        if(s[i] == '4') prefa[i]++;
        else prefb[i]++;
        //printf("%d. ", prefa[i]);
    }

    while(q--){
        int l,r,px,py;
        cin>>l>>r>>px>>py;
        l--;
        r--;

        int c4, c8;
        c4 = prefa[r];
        c8 = prefb[r];
        if(l > 0){
            c4-=prefa[l-1];
            c8-=prefb[l-1];
        }

        long long dis = abs(px) + abs(py);
        long long dskip = min(abs(px), abs(py));
        ll cnt;
        if(dskip < c8){
            cnt = dskip*2 + (c8-dskip);
        }
        else{
            cnt = c8*2;
        }

        if(dis - cnt <= c4) cout<<"YES\n";
        else cout<<"NO\n";
    }

}