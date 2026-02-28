#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sx(x) (int)(x).size()

mt19937_64 generator(chrono::steady_clock::now().time_since_epoch().count());

uniform_int_distribution<ll> distr(1, 1e18);

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n], b[n];

    long long suma = 0, sumb = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i]>>b[i];

        suma += a[i];
        sumb += b[i];
    }



    for(int i = 0; i < n; i++){
        long long bill = sumb;
        long long contrib = suma - a[i];
        if(bill-contrib <= b[i]){
            cout << (i+1) <<"\n";
            return 0;
        }


    }
    cout << "impossible\n";

}