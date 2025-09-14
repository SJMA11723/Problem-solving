#include<bits/stdc++.h>
#define set_bit(n, i) n |= (1 << (i))

using namespace std;

const int lim = (1 << 8);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> machines;

    int cnt[lim] = {};

    while(n--){
        char c; cin >> c;
        if(c == 'C'){
            int mask = 0;
            int r; cin >> r;
            while(r--){
                int x; cin >> x; x--;
                set_bit(mask, x);
            }
            cnt[mask]++;
            machines.push_back(mask);
        } else if(c == 'D'){
            int id; cin >> id; id--;
            cnt[ machines[id] ]--;
        } else {
            int mask = 0;
            int r; cin >> r;
            while(r--){
                int x; cin >> x; x--;
                set_bit(mask, x);
            }

            int ans = 0;
            for(int m = 0; m < lim; ++m){
                if(m & mask != mask) continue;
                ans += cnt[m];
            }

            cout << ans << '\n';
        }
    }
}



