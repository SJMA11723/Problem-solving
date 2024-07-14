/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t P = 31;
const int64_t MOD = 1e9 + 9;

vector<int> prefix_funtion(vector<int> &segment, vector<int> &arr){
    vector<int> all = segment;
    all.push_back(INT_MIN);
    for(int x : arr) all.push_back(x);
    int n = all.size();

    vector<int> pi(n);
    for(int i = 1; i < n; ++i){
        int j = pi[i - 1];
        while(j > 0 && all[i] != all[j]) j = pi[j - 1];
        if(all[i] == all[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<string> w(n);
    vector<int> w_h;
    int total_size = -1;
    for(string  &s: w){
        cin >> s;

        total_size += s.size() + 1;

        int64_t s_hash = 0;
        for(int i = 0; i < s.size(); ++i) s_hash = (s_hash * P + s[i]) % MOD;
        w_h.push_back(s_hash);
    }

    int ans = total_size;
    for(int i = 0; i < n; ++i){
        vector<int> segment;
        int segment_size = 0;
        for(int j = i; j < n; ++j){
            segment.push_back(w_h[j]);
            segment_size += w[j].size();
            if(j != i) segment_size++;

            vector<int> pi = prefix_funtion(segment, w_h);

            int new_size = total_size - segment_size + (int)segment.size();
            int last_r = j, last_l = i;
            for(int k = 0; k < pi.size(); ++k){
                if(pi[k] == segment.size()){
                    int l = k - 2 * (int)segment.size();
                    int r = l + pi[k] - 1;
                    if(l <= last_r || (last_l <= l && l <= last_r) || (last_l <= r && r <= last_r)) continue;

                    new_size += (int)segment.size() - segment_size;
                    last_l = l;
                    last_r = r;
                }
            }
            if(last_l != i && last_r != j) ans = min(ans, new_size);
        }
    }
    cout << ans << '\n';
}
