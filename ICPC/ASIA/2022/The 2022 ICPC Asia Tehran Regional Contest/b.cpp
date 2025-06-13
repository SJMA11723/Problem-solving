#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <algorithm>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const int64_t MOD = 1e9 + 7;

struct car{
    int d, v, idx;

    const bool operator<(const car &b)const{
        return d * b.v < b.d * v;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, f; cin >> n >> f;
    vector<car> arr(n);
    for(int i = 0; i < n; ++i){
        int d, v; cin >> d >> v;
        d = f - d;
        arr[i] = car{d, v, i + 1};
    }
    sort(all(arr));
    cout << arr[0].idx << '\n';
}