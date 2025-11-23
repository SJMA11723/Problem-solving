/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

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
#define pb push_back
#define sz(x) (int)(x).size()

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        int d[q];
        for(int &x : d) cin >> x;

        stack<int> H;
        H.push(1);
        for(int i = 2; i <= d[0] + 1; ++i){
            cout << i << ' ' << H.top() << '\n';
            H.push(i);
        }

        stack<int> V;
        V.push(2);
        for(int i = d[0] + 2; i <= n; ++i){
            cout << i << ' ' << V.top() << '\n';
            V.push(i);
        }

        cout << "-1 -1 -1\n";
        for(int i = 1; i < q; ++i){
            if(d[i] == d[i - 1]){
                cout << "-1 -1 -1\n";
                continue;
            }

            stack<int> move;
            if(d[i] < d[i - 1]){
                int diff = d[i - 1] - d[i];
                while(diff--){
                    move.push(H.top());
                    H.pop();
                }

                cout << move.top() << ' ' << H.top() << ' ' << V.top() << '\n';

                while(move.size()){
                    V.push(move.top());
                    move.pop();
                }
            } else {
                int diff = d[i] - d[i - 1];
                while(diff--){
                    move.push(V.top());
                    V.pop();
                }

                cout << move.top() << ' ' << V.top() << ' ' << H.top() << '\n';

                while(move.size()){
                    H.push(move.top());
                    move.pop();
                }
            }
        }
    }
}