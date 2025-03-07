    #include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    s = "#" + s;
    int m; cin >> m;

    int pow10[n + 1];
    pow10[0] = 1;
    for(int i = 1; i <= n; ++i) pow10[i] = 10 * pow10[i - 1] % m;

    bool dp[n + 1][m][10];
    memset(dp, 0, sizeof(dp));

    if(s[1] == '?'){
        for(int d = n == 1 ? 1 : 0; d < 10; ++d) dp[1][d % m][d] = true;
    } else {
        int d = s[1] - '0';
        dp[1][d % m][d] = true;
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 0; j < m; ++j){
            if(s[i] == '?'){
                for(int d = i == n ? 1 : 0; d < 10; ++d){

                    int mod = (j - (d * pow10[i - 1] % m) + m) % m;

                    for(int d2 = 0; d2 < 10; ++d2){
                        dp[i][j][d] |= dp[i - 1][mod][d2];
                    }
                }
            } else {
                int d = s[i] - '0';

                int mod = (j - (d * pow10[i - 1] % m) + m) % m;

                for(int d2 = 0; d2 < 10; ++d2){
                    dp[i][j][d] |= dp[i - 1][mod][d2];
                }
            }
        }
    }

    string ans;
    int mod = 0;
    for(int i = n; 0 < i; --i){
        if(s[i] != '?'){
            int d = s[i] - '0';

            ans += to_string(d);
            mod = (mod - (d * pow10[i - 1] % m) + m) % m;
            continue;
        }

        for(int d = (i == n ? 1 : 0); d < 10; ++d){
            if(dp[i][mod][d]){
                ans += to_string(d);
                mod = (mod - (d * pow10[i - 1] % m) + m) % m;
                break;
            }
        }
    }

    if(ans.size() == n) cout << ans << '\n';
    else cout << "*\n";
}
