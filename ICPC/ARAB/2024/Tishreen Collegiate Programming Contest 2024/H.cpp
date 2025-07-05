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
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()s
#define pb push_back
#define sz(x) (int)(x).size()
#define DEBUG if(debbb)
#define MAXN 2000000
const int MOD = 1e9 + 7;
bool debbb = false;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){string sep; for(const T &x : v) os << sep << x, sep = " "; return os;}
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}






long long binexp(long long x, int n){
    if(n == 1) return x;
    else if(n%2 == 0){
        long long ans = binexp(x, n/2);
        return (ans*ans) % MOD;
    }
    else return (x*binexp(x, n-1))%MOD;
}

long long inv(long long x){
    return binexp(x, MOD-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    
    int t;
    cin>>t;


    while(t--){
        int n;
        cin>>n;

        vector<int> freqs(n+1, 0), divs(n+1, 0), getdiv(n+1,0);
        int arr[n];
        for(int x = 0; x < n; x++){
            cin>>arr[x];
            freqs[arr[x]]++;
        }
        divs[1]=freqs[1];
        for(int i = 1; i <= n; i++){
            for(long long j = 2; i*j <= n; j++){
                divs[i]+=freqs[i*j];    
                getdiv[i*j]+=freqs[i];
            }
        }

        DEBUG deb(divs,getdiv);
        int ones = freqs[1];
        int ans = n-ones;
        for(auto x : arr){
            if(x == 1) continue;
            int tans = getdiv[x]+divs[x]+2*(n-freqs[x]-divs[x]-getdiv[x]);
            DEBUG deb(x, freqs[x], divs[x], tans, getdiv[x]);
            ans = min(ans,tans);
        }
        cout<<ans<<"\n";
    }
}