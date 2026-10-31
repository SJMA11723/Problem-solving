#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        sum += (x + k - 1) / k;
    }
    cout << sum << '\n';
}