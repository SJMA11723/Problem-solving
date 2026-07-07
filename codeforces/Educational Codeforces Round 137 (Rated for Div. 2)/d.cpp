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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

#define MAXLEN 1000000

template<int len = 1> void solve(const int n, const string &s){
    if(n > len){
        solve<min(len * 2, MAXLEN)>(n, s);
        return;
    }
    bitset<len> ans(s), cur(s);
    int len2 = n;
    bool one = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1') one = 1;
        if(one && s[i] == '0'){
            len2 = n - i;
            break;
        }
    }

    bitset<len> window(s.substr(0, len2));
    if(s[0] == '1') ans |= window;
    for(int i = len2; i < n; ++i){
        window[len2 - 1] = 0;
        window <<= 1;
        window[0] = s[i] - '0';
        bitset<len> tmp = cur | window;
        if(ans.to_string() < tmp.to_string()) ans = tmp;
    }
    one = 0;
    for(int i = len - 1; 0 <= i; --i){
        if(one) cout << ans[i];
        else if(ans[i]) one = 1, cout << '1';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    if(*max_element(all(s)) == '0'){
        cout << "0\n";
        return 0;
    }
    solve(n, s);
}
