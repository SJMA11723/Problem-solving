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

const bool deb = 0;
#define DEBUG if(deb)

const int MOD = 1e9 + 7;

int select_table(deque<int> &past, deque<int> &present, deque<int> &alone_ambi, bool &ret_present){
    int res = -1;
    if(sz(present)){
        res = present.back();
        present.pop_back();
        ret_present = 1;
    } else if(sz(past)){
        res = past.back();
        past.pop_back();
        ret_present = 0;
    } else {
        res = alone_ambi.front();
        alone_ambi.pop_front();
        ret_present = 0;
    }

    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x, s; cin >> n >> x >> s;
        string str; cin >> str;
        int N = 2 * min(n, x);
        int empty = x;
        // guarda la cantidad de asientos disponibles por mesa
        deque<int> past, present, alone_ambi;
        vi cnt_table(N, s - 1);

        int nxt_table = 0;
        int ans = 0;
        for(char c : str){
            DEBUG cout << c << ' ';
            if(c == 'I'){
                if(empty > 0){
                    empty--;
                    if(s - 1 > 0) present.push_back(nxt_table);
                    nxt_table++;
                    ans++;
                } else if(sz(alone_ambi) > 0 && sz(past) + sz(present) + sz(alone_ambi) >= 2){
                    // reacomodo al ambivertido
                    int cur_table = -1;
                    int last_ambi = alone_ambi.back();
                    alone_ambi.pop_back();

                    while(sz(past) && last_ambi < past.back()){
                        present.push_front(past.back());
                        past.pop_back();
                    }


                    bool ok = 1;
                    if(sz(past)){
                        cnt_table[past.back()]--;
                        if(cnt_table[past.back()] == 0) past.pop_back();
                        ans++;
                    } else if(sz(alone_ambi)){
                        cnt_table[alone_ambi.front()]--;
                        if(cnt_table[alone_ambi.front()] > 0) past.push_back(alone_ambi.front());
                        alone_ambi.pop_front();
                        ans++;
                    } else alone_ambi.push_back(last_ambi), ok = 0;

                    if(ok){
                        if(s - 1 > 0) present.push_back(nxt_table);
                        nxt_table++;
                    }
                }
            } else if(c == 'E'){
                if(sz(past) + sz(present) + sz(alone_ambi) > 0){
                    bool ret;
                    int cur_table = select_table(past, present, alone_ambi, ret);
                    cnt_table[cur_table]--;
                    if(cnt_table[cur_table] > 0) ret ? present.push_back(cur_table) : past.push_back(cur_table);
                    ans++;
                }
            } else {
                if(empty > 0){
                    empty--;
                    if(s - 1 > 0){
                        alone_ambi.push_back(nxt_table);
                        while(sz(present) && present.front() < nxt_table){
                            past.push_back(present.front());
                            present.pop_front();
                        }
                    }
                    nxt_table++;
                    ans++;
                } else if(sz(past) + sz(present) + sz(alone_ambi) > 0){
                    bool ret;
                    int cur_table = select_table(past, present, alone_ambi, ret);
                    cnt_table[cur_table]--;
                    if(cnt_table[cur_table] > 0) ret ? present.push_back(cur_table) : past.push_back(cur_table);
                    ans++;
                }
            }

            DEBUG{
                cout << ans << '\n';
                cout << "alone ambi = " << sz(alone_ambi) << '\n';
                cout << "empty = " << empty << '\n';
                cout << "past = " << sz(past) << '\n';
                cout << "present = " << sz(present) << '\n';
            }
            
        }

        cout << ans << '\n';
    }
}