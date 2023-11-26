/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

map< pair<int, int>, bool > processed;
map< pair<int, int>, vector<int> > dp;
vector<int> divisor;

vector<int> compute(int n, int p){
    if(n == 0) return {};

    if(processed[{n, p}]) return dp[{n, p}];

    processed[{n, p}] = true;

    //cout << n << ' ' << p << '\n';
    for(int d : divisor){
        if(n == d && p == d)
            return dp[{n, p}] = {d};

        if(p % d || n < d) continue;
        //cout << "hola " << d << ' ' << n << '\n';

        vector<int> tmp = compute(n - d, p / d);
        tmp.push_back(d);

        long long mult = 1;
        for(long long x : tmp) mult *= x;
        if(mult != p) continue;

        if(dp[{n, p}].empty() || tmp.size() < dp[{n, p}].size())
            dp[{n, p}] = tmp;
    }

    return dp[{n, p}];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;

    for(int tt = 1; tt <= t; ++tt){
        int P; cin >> P;

        cout << "Case #" << tt << ": ";
        /*if(P <= 41){
            cout << 41 - P + 1 << ' ' << P;
            for(int i = 0; i < 41 - P; ++i) cout << "1 ";
            cout << '\n';
            continue;
        }*/

        divisor.clear();
        divisor.shrink_to_fit();

        int lim = sqrt(P);
        for(int i = 1; i <= lim; ++i){
            if(P % i == 0){
                divisor.push_back(i);
                if(i != P / i)
                    divisor.push_back(P / i);
            }
        }

        processed.clear();
        dp.clear();

        compute(41, P);

        if(dp[{41, P}].empty() || dp[{41, P}].size() > 100) cout << "-1";
        else {
            cout << dp[{41, P}].size() << ' ';
            for(int d : dp[{41, P}]) cout << d << ' ';
        }
        cout << '\n';

        //for(int d : divisor) cout << d << ' ';
        //cout << '\n';
    }

}
