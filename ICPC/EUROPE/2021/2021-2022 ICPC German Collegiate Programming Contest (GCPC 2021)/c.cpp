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
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, 1e18);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.fi << ", " << p.se << ')';}
template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream & operator<<(ostream &os, const C &v){string sep;for(const T &x : v) os << sep << x, sep = " "; return os;}

#define PRINT(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "]\n";
}

const int MOD = 1e9 + 7;



int bsearch(int n, long double price, vector<pair<long double, int>>& arr){
    int ini = 0, fin = n-1;
    int ans = -1;
    while(ini <= fin){
        int mit = (ini+fin)/2;

        if(arr[mit].first <= price){
            ans = mit;
            ini = mit+1;
        }
        else{
            fin = mit-1;
        }
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pair<long double, int> > buys, sells;


    for(int i = 0; i < n; i++){
        long double p;
        int b,s;

        cin>>p>>b>>s;

        if(b > 0){
            buys.push_back({p, b});
        }
        if(s > 0){
            sells.push_back({p, s});
        }
    }
    int bn = buys.size(), sn = sells.size();

    if(bn == 0 || sn == 0){
        cout<<"impossible\n";
        return 0;
    }

    sort(buys.begin(), buys.end());
    sort(sells.begin(), sells.end());

    

    ll suff[bn];
    suff[bn-1] = buys[bn-1].second;
    for(int i = bn-2; i >= 0; i--){
        suff[i] = suff[i+1] + buys[i].second;
    }
    ll preff[sn];
    preff[0] = sells[0].second;
    for(int i = 1; i < sn; i++){
        preff[i] = preff[i-1] + sells[i].second;
    }
    bool flag = false;
    long double price, maxgain = -1e18;
    for(int i = 0; i < bn; i ++){
        long double p = buys[i].first;
        ll bfreqs = suff[i];

        int idx = bsearch(sn, p, sells);
        if(idx == -1) continue;
        ll sfreqs = preff[idx];

        ll sc = min(sfreqs, bfreqs);
        //cout<<p<<" "<<i<<"\n";
        //printf("%lf %d, sf%d, bf%d\n",p, i, sfreqs, bfreqs);
        long double gain = sc*p;
        if(gain >= maxgain){
            flag = true;
            price = p;
            maxgain = gain;
        }
    }
    
    if(!flag) cout<<"impossible\n";
    else{
        cout<<fixed<<setprecision(2)<<price<<" "<<maxgain<<"\n";
    }
}
