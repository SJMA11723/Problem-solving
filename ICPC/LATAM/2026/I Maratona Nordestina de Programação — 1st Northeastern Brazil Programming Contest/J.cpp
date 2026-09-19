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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const int MOD = 1e9 + 7;

template<typename A, typename B> ostream&operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}
#define print(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename ...Args> void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

const bool deb = 0;
#define DEBUG if(deb)

struct node{
    ll val; ll lazy;
    node( ) : val(0), lazy(0) {}
    node( ll x, int  lz = 0 ) : val(x), lazy(lz) {}
    const node operator + ( const node &b) const{
        return node( max(val, b.val) );
    }
};

struct segment_tree{

    vector<node> nodes;

    segment_tree( int n, int data[] ){
        nodes.resize( 4 * n +1 );
        build( 1, n, data);
    }


    void build( int left, int right, int data[], int pos = 1 ){
        if( left == right ){
            nodes[pos] = node( data[left]);
            return;
        }
        int mid = (left + right) / 2;
        build( left, mid, data, pos*2);
        build( mid+1, right, data, pos *2 + 1 );
        nodes[pos] = nodes[ pos* 2] + nodes[pos*2+1];
    }

    node query( int l, int r, int left, int right, int pos =1){
        if( r < left || right < l) return node();
        if( l <= left && right <= r){
            return nodes[pos];
        }
        int mid = (left+right)/2;
       return query( l,r, left, mid, pos*2) + query(l,r, mid+1, right, pos*2+1);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q; cin >> n >> q;

    int arr[n+2];
    for( int i=1 ; i<=n; i++ ) cin >> arr[i];
    

    segment_tree st(n, arr);

    while( q-- ){
        int l,r; cin >> l >> r;

        node maxi_n = st.query(l, r,      1, n);
        int maxi = maxi_n.val;

        if( maxi == arr[l] || maxi == arr[r] ){
            cout << "Adilson\n";
        }else{
            int mov = l - r + 1 - 3;

            if( mov % 2 ) cout << "Adilson\n";
            else cout << "Reginaldo\n";
        }

    }

}