#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
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
#define sz(x) (int)(x).size()
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int b[n];
    int t[n];
    for(int i = 0; i < n; i++){
        cin>>b[i]>>t[i];
    }
    int tans[n];

    stack<int> s;
    s.push(0);

    for(int i = 1; i < n; i++){
        if(t[i] == t[i-1])s.push(i);
        else{
            while(!s.empty()){
                int ti = s.top();
                s.pop();
                tans[ti] = i;
            }
            s.push(i);
        }
    }
    
    while(!s.empty()){
        int ti = s.top();
        s.pop();
        tans[ti] = -1;
    }

    while(m--){
        int myb, myt;
        cin>>myb>>myt;

        int ini = 0, fin = n-1;
        int ans = -1;
        while(ini <= fin){
            int mit = (ini+fin)/2;
            if(b[mit] <= myb){
                //cout<<"mit"<<mit<<"\n";
                ans = mit;
                fin = mit-1;
            }
            else{
                ini = mit+1;
            }
        }

        if(ans == -1 ){
            cout<<"-1\n";
            continue;
        }
        if(t[ans] == myt) {
            if(tans[ans] == -1) cout<<"-1\n";
            else cout<<tans[ans]+1<<"\n";
        }
        else cout<<ans+1<<"\n";
    }
}