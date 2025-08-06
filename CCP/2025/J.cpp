#include <bits/stdc++.h>

using namespace std;

int val[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str; cin >> str;
    int n = str.size();
    int sum = 0;
    for(char c : str) sum += val[c - '0'];

    bool dp[n + 1][800][10];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < 10; ++i) dp[1][val[i]][i] = 1;

    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= sum; ++j){
            for(int k = 0; k < 10; ++k){
                if(j - val[k] < 0) continue;

                for(int d = 0; d < 10; ++d){
                    if(dp[i - 1][j - val[k]][d]){
                        dp[i][j][k] = 1;
                        break;
                    }
                }
            }
        }
    }

    string ans;
    for(int i = n; 0 < i; --i){
        int digit = -1;
        for(int d = 9; 0 <= d; --d){
            if(dp[i][sum][d]){
                digit = d;
                break;
            }
        }
        ans += char(digit + '0');
        sum -= val[digit];
    }
    cout << ans << '\n';
}