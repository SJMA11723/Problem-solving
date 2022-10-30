#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b, h, w;
    while(cin >> n >> b >> h >> w){
        int ans = 1e9;

        for(int i = 0; i < h; ++i){
            int p; cin >> p;
            for(int j = 0; j < w; ++j){
                int c; cin >> c;
                if(n <= c)
                    ans = min(ans, p * n);
            }
        }

        if(ans <= b){
            cout << ans << '\n';
        } else cout << "stay home\n";
    }
}
