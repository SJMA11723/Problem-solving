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
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
#define DEBUG if(debbb)
#define MAXN 60
#define MAXS 600000

long long dp[MAXN][MAXS];

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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int arr[n];
    long long sum = 0;
    for(int x = 0; x < n; x++){
        cin>>arr[x];
        sum+=arr[x];
    }

    sort(arr, arr+n);

    
    long long mit = sum/2; 
    long long ans = 0;
    dp[n-1][arr[n-1]] = 1;
    dp[n-1][0] = 1;
    if(arr[n-1] > mit) ans++;


    for(int i = n-2; i>=0; i--){
        for(int s = 0; s <= sum; s++){
            if(s-arr[i]>= 0)dp[i][s]+=dp[i+1][s-arr[i]];
            if(mit < s && s <= mit +arr[i]) ans+=dp[i][s];
            dp[i][s]+=dp[i+1][s];
        }
    }
    cout<<ans<<"\n";
}