#include<bits/stdc++.h>




using namespace std;


typedef int64_t ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;


#define fi first  
#define se suseconds_t
#define all(x) (x).begin(), (x).end
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    int maxi[m] = {};
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int x; cin >> x;
            maxi[j] = max(maxi[j], x);
        }
    }

    cout << accumulate(maxi, maxi + m, 0) << '\n';
}