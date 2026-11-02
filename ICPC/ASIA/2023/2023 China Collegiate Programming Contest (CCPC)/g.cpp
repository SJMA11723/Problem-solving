#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define repr(i, a, b) for(int i = (b) - 1; a <= i; --i)
const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;

   while(t--){
        string s ; cin >> s;

        int  level= 0;
        for( char c : s){
            if( c == '(') level++;
            if( c == ')' && level >0) level--;
        }

        // cout << level << "\n";
        if( level != 0 ){
            cout << "impossible\n";
            continue;;
        }
        cout << s <<"\n";
    }

}