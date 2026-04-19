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

int main(){
    string begin = "abcdefghijklmnopqrstuvwxyz";
    cout<<"? "<<begin<<endl;
    int n;
    cin>>n;
    int t;
    for(int i = 0; i < n; i++) cin>>t;
    vector<int> letters;
    for(int i = 0; i <26; i++) letters.push_back(i);
    vector<int> ans(n, 0);
    for(int i = 0; i < 5; i++){
        string query;
        for(auto letter : letters){
            if(letter & (1<<i)) query.push_back('a'+letter);
        }
        cout<<"? "<<query<<endl;
        int nt;
        cin>>nt;

        for(int j = 0; j < nt; j++){
            int pos;
            cin>>pos;
            pos--;
            ans[pos] = ans[pos] | (1<<i);
        }
    }
    string s;
    for(int i = 0; i < n; i++){
        s.push_back('a'+ans[i]);
    }

    cout<<"! "<<s<<endl;
}