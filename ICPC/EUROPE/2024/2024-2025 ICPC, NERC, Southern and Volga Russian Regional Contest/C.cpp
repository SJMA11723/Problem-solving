#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, int> cnt;
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            cnt[x]++;
        }

        int points[4];
        fill(points, points + 4, INT_MIN);

        for(auto &it : cnt){
            if(points[1] != INT_MIN) break;
            if(it.second >= 2 && points[0] == INT_MIN){
                points[0] = it.first;
                it.second -= 2;
            }

            if(it.second >= 2){
                points[1] = it.first;
                it.second -= 2;
            }
        }

        for(auto it = cnt.rbegin(); it != cnt.rend(); ++it){
            if(points[3] != INT_MIN) break;

            if(it->second >= 2 && points[2] == INT_MIN){
                points[2] = it->first;
                it->second -= 2;
            }

            if(it->second >= 2){
                points[3] = it->first;
                it->second -= 2;
            }
        }

        sort(points, points + 4);

        if(points[0] == INT_MIN) cout << "NO\n";
        else {
            cout << "YES\n";
            int ans[4];
            int64_t max_area = 0;
            do{
                int64_t area = 1ll * abs(points[0] - points[1]) * abs(points[2] - points[3]);
                if(max_area <= area){
                    max_area = area;
                    memcpy(ans, points, sizeof(ans));
                }
            }while(next_permutation(points, points + 4));

            cout << ans[0] << ' ' << ans[2] << ' ';
            cout << ans[0] << ' ' << ans[3] << ' ';
            cout << ans[1] << ' ' << ans[2] << ' ';
            cout << ans[1] << ' ' << ans[3] << '\n';
        }
    }
}
