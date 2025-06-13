#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <climits>

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i, j; cin >> n >> i >> j;
    i--, j--;

    vector<bool> vis(2 * n);
    queue<pii> q;
    q.push({i, 0});
    vis[i] = 1;
    while(q.size()){
        int cur, d;
        tie(cur, d) = q.front();
        q.pop();

        if(cur == j){
            cout << d << '\n';
            return 0;
        }

        vis[cur] = 1;

        int v = 2 * (cur % n) + cur / n;
        if(!vis[v]){
            q.push({v, d + 1});
            vis[v] = 1;
        }

        v = cur ^ 1;
        if(!vis[v]){
            q.push({v, d + 1});
            vis[v] = 1;
        }
    }

    cout << "-1\n";
}