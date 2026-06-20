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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x, s; cin >> n >> x >> s;
        string str; cin >> str;
        int empty = x;
        // guarda la cantidad de asientos disponibles por mesa
        priority_queue<int> nonempty;

        // seat ambi only in nonempty tables until final assignment
        int pending_ambi = 0, seated_ambi = 0;
        int ans = 0;
        for(char c : str){
            //cout << c << ' ';
            if(c == 'I'){
                if(empty){
                    empty--;
                    if(s - 1) nonempty.push(s - 1);
                    ans++;
                }
            } else if(c == 'E'){
                if(sz(nonempty)){
                    int cur_table = nonempty.top() - 1;
                    nonempty.pop();
                    if(cur_table) nonempty.push(cur_table);
                    ans++;
                } else if(empty > 0 && pending_ambi > 0 && s >= 2){
                    pending_ambi--;
                    empty--;
                    int cur_table = s - 2;
                    ans += 2;
                    while(cur_table > 0 && pending_ambi > 0){
                        cur_table--;
                        pending_ambi--;
                        seated_ambi++;
                        ans++;
                    }
                    if(cur_table) nonempty.push(cur_table);
                } else if(seated_ambi > 0){
                    pending_ambi++;
                    seated_ambi--;
                }
            } else {
                if(sz(nonempty)){
                    int cur_table = nonempty.top() - 1;
                    nonempty.pop();
                    if(cur_table) nonempty.push(cur_table);
                    seated_ambi++;
                    ans++;
                } else pending_ambi++;
            }

            /*
            cout << ans << '\n';
            cout << "seated ambi = " << seated_ambi << '\n';
            cout << "pending ambi = " << pending_ambi << '\n';
            cout << "empty = " << empty << '\n';
            cout << "nonempty = " << sz(nonempty) << '\n';
            */
        }

        // final assignment
        int mini = min(1ll * empty * s, 1ll * pending_ambi);
        ans += mini;
        pending_ambi -= mini;

        while(sz(nonempty) && pending_ambi > 0){
            pending_ambi--;
            int mini = min(pending_ambi, nonempty.top());
            ans += mini;
            pending_ambi -= mini;
            nonempty.pop();
        }

        cout << ans << '\n';
    }
}