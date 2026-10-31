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

char f(char c){
    if('A' <= c && c <= 'Z') return c - 'A' + 'a';
    return c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n = sz(s);
    int blocks = 0;
    for(int i = 0; i < n; ++i){
        if(i && s[i] == ':' && s[i - 1] != ':')
            blocks++;
    }
    if(s.back() != ':') blocks++;

    string block, ans;
    char prv = 0;
    for(char c : s){
        if(c == ':'){
            if(prv == ':'){
                if(sz(ans)) ans += ':';
                while(blocks < 8){
                    ans += "0000:";
                    blocks++;
                }
                ans.pop_back();
            } else if(sz(block)){
                if(sz(ans)) ans += ':';
                ans += string(4 - sz(block), '0');
                ans += block;
            }
            block = "";
        } else block += f(c);
        prv = c;
    }
    if(sz(block)){
        ans += ":" + string(4 - sz(block), '0');
        ans += block;
    }

    cout << ans << '\n';
}