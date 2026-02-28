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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back

const int MOD = 1e9 + 7;


#define INF 10000
int contar(string s){
    char primero = s[0];
    int cnt = 0;
    for( char c: s){
        if( c!=  primero ) break;
        cnt++;
    }
    if( cnt == s.size() ) return INF;
    return cnt;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    int cnt[ 'z' - 'a'  + 1 ] = {};

    int n,e; cin >> n >> e; 
    
    string keys[n],s;

    for( int i=0; i<n; i++ ){
        cin >> s; keys[i] = s;
        cnt[  s[0]  - 'a' ] += contar(  s);
        //cout << s[0] << ' ' << contar(s) << '\n';
    }

    bool todasInf = true;
    int mini = INF;
    char quien = '.';

    for( char c = 'a'; c < 'a' + e ; c++  ){
        if( cnt[c - 'a'] < INF  ) todasInf = false;
        if( mini > cnt[c - 'a']  ){
            mini = cnt[c - 'a'];
            quien = c;
        }
        //cout << c << " " <<  cnt[c - 'a'] << '\n';
    }
    // entonces siempre se peude
    if( todasInf ){
        cout << "NO\n";
        return 0;
    }



    //cout << mini << '\n';
    for(  int i=0; i<= mini; i++  ) cout << quien;
    cout << '\n';


}