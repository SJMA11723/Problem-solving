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


bool esNum( char c){
    return (c-'0' >=0 ) && ( c - '0' <=9);
}
bool esPa( char c){
    return (c=='(') || (c == ')');
}
bool esSig( char c){
    return (c=='+') || (c == '-');
}
bool abre( char c){
    return (c=='(');
}
bool cierra( char c){
    return (c == ')');
}

void solve( int ini, int fin, string &s, string &sans, vi &donde_cierra){
    int n = sz(s);
    int next = ini;
    if( esNum(s[ini]) ){
        // no hacemos nada
        while( next <= fin && esNum( s[next])   ) next++;
        // cout << "caso1:" <<  s[next] << " " << next << "\n";
    }
    // tiene que ser (
    else{ 
        next = donde_cierra[ini] +1; // el que va depsues de )
        solve(ini+1, donde_cierra[ini]-1, s, sans, donde_cierra);
    }

    while( esPa( s[next])   && next <= fin ) next++;
    if( next >= fin ) return;

    // el siueinte ahuevo es signo
    sans[next] = '-'; next++;
    int nivel = 0;
    for( int i = next; i<=fin; i++ ){
        int c = s[i];
        if( abre(c) ) nivel ++;
        if( cierra(c) ) nivel--;
        
        if( esSig(c) ){
            if( nivel > 0 ) sans[i] = '+';
            if( nivel == 0 ) sans[i] = '-';
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    string s; cin >> s;
    string sans = s;
    int n = sz(s);
    // peclacular 
    vi donde_cierra(n+1,-1);
    stack<int> p;

    for( int i=n-1; i>=0; i--){
        if( s[i] == ')') p.push(i);
        if( s[i] == '('){
            donde_cierra[i] = p.top();
            p.pop();
            // cout << i << " " << donde_cierra[i] << "\n";
        }
    }


    solve(0, n-1,s, sans, donde_cierra);

    // cout << s << "\n";
    cout << sans << "\n";
}



























