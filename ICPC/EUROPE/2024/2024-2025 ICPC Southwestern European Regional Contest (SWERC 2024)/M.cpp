#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;


#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int MOD = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);



    string s;
    cin >> s;

    for( char c: s ){
        if( c== 'O' || c== 'o' ) cout << ".-.-";
        else cout << ".-";
    }
    cout << '\n';


}
