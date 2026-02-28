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


int multdeDIEZ( int a ){
    a++;

    while(  a%10 != 0 ) a++;
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;


    int maxi=0;
    string limi;

    while( n-- ){
        cin >> limi;
        if( limi !=  "/" ){
            int l = stoi( limi );
            maxi = max( maxi, l );
            cout << l << '\n';

        }else{
            cout << multdeDIEZ( maxi ) << '\n';
        }


    }
}