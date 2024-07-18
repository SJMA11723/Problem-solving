/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    int pref_row[n + 1][m + 1], pref_col[n + 1][m + 1];
    memset(pref_col, 0, sizeof(pref_col));
    memset(pref_row, 0, sizeof(pref_row));

    int sum = 0;
    char mat[n + 1][m + 1];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> mat[i][j];
            if(mat[i][j] == '*') pref_col[i][j] = pref_row[i][j] = 1;
            pref_row[i][j] += pref_row[i][j - 1];
            pref_col[i][j] += pref_col[i - 1][j];
        }
        sum += pref_row[i][m];
    }

    bool ap[n + 1][m + 1];
    memset(ap, 0, sizeof(ap));
    int cnt = 0;
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(mat[i][j] != '*') continue;
            int l = 1, r = min({i, j, n - i + 1, m - j + 1});
            while(l < r){
                int mid = l + (r - l) / 2;

                set<int> mset;
                mset.insert(pref_row[i][j] - pref_row[i][j - mid - 1] - (mat[i][j] == '*'));
                mset.insert(pref_col[i][j] - pref_col[i - mid - 1][j] - (mat[i][j] == '*'));
                mset.insert(pref_row[i][j + mid] - pref_row[i][j]);
                mset.insert(pref_col[i + mid][j] - pref_col[i][j]);

                if(mset.size() == 1 && *mset.begin() == mid) l = mid + 1;
                else r = mid;
            }
            if(l > 1){
                ans.push_back({{i, j}, l - 1});
                for(int k = 0; k < l; ++k){
                    if(!ap[i][j + k]){
                        ap[i][j + k] = true;
                        cnt++;
                    }

                    if(!ap[i][j - k]){
                        ap[i][j - k] = true;
                        cnt++;
                    }

                    if(!ap[i + k][j]){
                        ap[i + k][j] = true;
                        cnt++;
                    }

                    if(!ap[i - k][j]){
                        ap[i - k][j] = true;
                        cnt++;
                    }
                }
            }
        }
    }

    if(cnt != sum){
        cout << "-1\n";
        return 0;
    }

    cout << ans.size() << '\n';
    for(auto p : ans) cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
}
