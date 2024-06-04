#include<bits/stdc++.h>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int64_t periodo[234] = {};
    for(int n = 3; n <= 233; ++n){
        for(int t = 1; t <= 12; ++t){
            for(int i = 0; i <= n; ++i){
                if(30 * t * n == 360 * i){
                    periodo[n] = t;
                    t = 12;
                    break;
                }
            }
        }
    }

    int t; cin >> t;
    while(t--){
        int64_t C, F, B, S;
        cin >> C >> F >> B >> S;

        int64_t lim = (S * 12 + C - 1) / C;
        int64_t P = lcm(periodo[F], periodo[B]);
        cout << lim << ' ' << P << '\n';
        cout << (lim + P - 1) / P * P << '\n';
    }

    return 0;
}
