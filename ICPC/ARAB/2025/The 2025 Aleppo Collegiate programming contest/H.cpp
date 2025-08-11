#include<bits/stdc++.h>
using namespace std;

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
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int t; cin >> t;

    while( t-- ){
        int n; cin >> n;
        vi arr(n);
        for( int &a : arr )cin >> a;


        cout << arr[0];

        for( int i=0; i<n;  ){
            if( i == n-1 )break;
            if( i+2 < n-1 && arr[i+2] < arr[i+1]  ){
                cout << ' '<< arr[i+2];
                cout << ' '<< arr[i+1];
                cout << ' '<< arr[i+3];
                i = i+3;
            }else{
                cout << ' '<< arr[i+1];
                i = i+1;
            }
        }
        cout << '\n';

    }
}
