/**
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
const string suits = "CDHS";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        char trump_suit; cin >> trump_suit;
        map<char, vector<char>> cub;
        for(int i = 0; i < n; ++i){
            string s; cin >> s;
            cub[s[1]].pb(s[0]);

            cin >> s;
            cub[s[1]].pb(s[0]);
        }

        bool ok = true;
        vector<pair<string, string> > ans;
        for(char c : suits){
            if(c == trump_suit) continue;

            if(sz(cub[c]) & 1){
                if(cub[trump_suit].empty()){
                    ok = false;
                    break;
                }

                string a, b;
                a += cub[c].back();
                a += c;
                b += cub[trump_suit].back();
                b += trump_suit;
                ans.pb({a, b});
                cub[c].pop_back();
                cub[trump_suit].pop_back();
            }
        }

        for(char c : suits){
            if(sz(cub[c]) & 1){
                ok = false;
                break;
            }
            if(!sz(cub[c])) continue;

            sort(all(cub[c]));

            while(sz(cub[c])){
                string a, b;
                b += cub[c].back(); cub[c].pop_back();
                a += cub[c].back(); cub[c].pop_back();
                a += c;
                b += c;
                ans.pb({a, b});
            }
        }

        if(!ok){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        
        for(auto [a, b] : ans) cout << a << ' ' << b << '\n';
    }
}