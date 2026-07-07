#include <bits/stdc++.h>

using namespace std;

int n;
string str;
long long arr[200000];
long long dp[200000][2];

long long compute(int pos, bool ant){
    if(n <= pos) return 0;

    if(dp[pos][ant] == -1){
        if(str[pos] == '0' || ant){
            dp[pos][ant] = (str[pos] - '0') * arr[pos] + compute(pos + 1, str[pos] - '0');
        } else dp[pos][ant] = max(arr[pos] + compute(pos + 1, 1), arr[pos - 1] + compute(pos + 1, 0));
    }

    return dp[pos][ant];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> str;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
            dp[i][0] = dp[i][1] = -1;
        }

        int first = 0;
        if(str[0] == '1') first = arr[0];

        cout << first + compute(1, str[0] - '0') << '\n';
    }
}