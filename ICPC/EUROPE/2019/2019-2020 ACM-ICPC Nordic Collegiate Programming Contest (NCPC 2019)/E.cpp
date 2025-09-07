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

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define pb push_back

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    getline(cin, str);
    int nxt = 0;
    for(char c : str){
        if(c == ' ') nxt++;
    }

    int n; cin >> n;
    bool cur_team = 0;
    vector<string> team[2], arr(n);
    for(string &s : arr) cin >> s;
    int pos = 0;


    while(sz(arr)){
        pos = (pos + nxt) % sz(arr);
        team[cur_team].pb(arr[pos]);
        arr.erase(arr.begin() + pos);
        cur_team = !cur_team;
    }

    for(int i = 0; i < 2; ++i){
        cout << sz(team[i]) << '\n';
        for(string &s : team[i]) cout << s << '\n';
    }
}