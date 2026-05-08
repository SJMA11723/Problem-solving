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
typedef vector<pii> vpii;
typedef vector<vll> vpll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define fi first
#define se second
#define all(x) (x).begin, (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distr(1, LLONG_MAX);

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.fi << ", " << p.se << ')';
}

template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream &os, const C &v){
    string sep;
    for(const T &x : v) os << sep << x, sep = " ";
    return os;
}

#define PRINT(...) logger(#__VA_ARGS__, __VA_ARGS__)

template<typename ...Args>
void logger(string vars, Args&&... values){
    cout << "[Debug]\n\t" << vars << " = ";
    string d = "[";
    (..., (cout << d << values, d = "] ["));
    cout << "\n";
}

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int arr[n];
    set<pii> nums;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        nums.insert({arr[i], i});
    }

    vpii ans;
    while(nums.rbegin()->first - nums.begin()->first > 1){
        int i = nums.begin()->second;
        int j = nums.rbegin()->second;
        nums.erase(nums.begin());
        nums.erase(*nums.rbegin());

        int s = arr[i] + arr[j];
        arr[i] = s / 2;
        arr[j] = (s + 1) / 2;

        nums.insert({arr[i], i});
        nums.insert({arr[j], j});

        ans.pb({i + 1, j + 1});
    }

    int l = 0, r = n - 1;
    int m = nums.begin()->first, M = nums.rbegin()->first;
    while(l < r){
        if(arr[l] == m){
            l++;
            continue;
        }

        if(arr[r] == M){
            r--;
            continue;
        }

        swap(arr[l], arr[r]);
        ans.pb({l + 1, r + 1});
    }

    cout << sz(ans) << '\n';
    for(auto [i, j] : ans) cout << i << ' ' << j << '\n';
}