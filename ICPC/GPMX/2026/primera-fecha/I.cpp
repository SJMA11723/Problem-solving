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

const int MOD = 1e9 + 7;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

const bool DEB = false;
#define DEBUG if(DEB)
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n; cin >> n;

    ll a[n];
    for( int i=0; i<n; i++) cin >> a[i];
    string s; cin >> s;


 

    

    //  delane para atras
    ll arr[n];
    ll mini = 1;
    arr[0] = 1;
    for( int i=1; i<n; i++){
        char c = s[i-1];
        arr[i] = arr[i-1];
        // if( c == '=')
        if( c == '>') arr[i] = 1;
        if( c == '<') arr[i]++;
    }


    //  atras para deltante
    ll arr2[n];
    ll mini2 = 1;
    arr2[n-1] = 1;
    for( int i=n-2; i>=0; i--){
        char c = s[i];
        arr2[i] = arr2[i+1];

        if( c == '>') arr2[i]++;
        if( c == '<') arr2[i] = 1;
        
    }

    // juntar 
    // ll sum = 1 - mini;
    // ll sum2 = 1 - mini2;
    ll arr3[n];
    for( int i=0; i<n; i++ ){
        // arr[i] += sum;
        // arr2[i] += sum2;
        arr3[i] = max( arr[i], arr2[i]);
    }



    DEBUG{
        for( int i=0; i<n; i++ ){
            cout << arr[i] << " \n"[ i==n-1];
        }
        for( int i=0; i<n; i++ ){
            cout << arr2[i] << " \n"[ i==n-1];
        }

        for( int i=0; i<n; i++ ){
            cout << arr3[i] << " \n"[ i==n-1];
        }


    }


    ll ans = 0;
    for( int i=0; i<n; i++ ){
        ans+= a[i] * arr3[i];
    }


    cout << ans << '\n';
    for( int i=0; i<n; i++ ){
        cout << arr3[i] << " \n"[i==n-1];
    }

}