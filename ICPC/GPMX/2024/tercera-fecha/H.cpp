#include <bits/stdc++.h>
#define is_on(n, i) ((n) & (1 << (i)))

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string m, n; cin >> m >> n;
    vector<pair<int, bool> > asteriscos;
    for(int i = 0; i < m.size(); ++i) if(m[i] == '*') asteriscos.push_back({i, 0});
    for(int i = 0; i < n.size(); ++i) if(n[i] == '*') asteriscos.push_back({i, 1});

    int lim = 1 << asteriscos.size();
    for(int mask = 0; mask < lim; ++mask){
        string M = m, N = n;
        for(int i = 0; i < asteriscos.size(); ++i){
            if(asteriscos[i].second) N[asteriscos[i].first] = is_on(mask, i) ? '1' : '0';
            else M[asteriscos[i].first] = is_on(mask, i) ? '1' : '0';
        }

        int64_t num = 0, pow2 = 1;
        for(int i = (int)N.size() - 1; 0 <= i; --i){
            num += pow2 * (N[i] - '0');
            pow2 *= 2;
        }

        int64_t res = 0;
        pow2 = 1;
        for(int i = (int)M.size() - 1; 0 <= i; --i){
            res += pow2 * (M[i] - '0');
            if(res >= num) res -= num;

            pow2 += pow2;
            if(pow2 >= num) pow2 -= num;
        }

        if(!res){
            cout << M << '\n';
            return 0;
        }
    }
}
