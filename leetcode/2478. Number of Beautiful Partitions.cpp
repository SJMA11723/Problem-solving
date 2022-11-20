class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[1001][1001];

    bool prime(int x){
        return x == 2 || x == 3 || x == 5 || x == 7;
    }

    int compute(const string &s, int n, int k, const int &minLength){
        if(n < 0 || k < 0) return 0;

        if(dp[n][k] == -1){
            dp[n][k] = 0;
            for(int i = n - minLength + 1; 1 <= i; --i){
                if(prime(s[i - 1] - '0') && !prime(s[n - 1] - '0')){
                    dp[n][k] += compute(s, i - 1, k - 1, minLength);
                    dp[n][k] %= MOD;
                }
            }
        }

        return dp[n][k];
    }

    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();

        memset(dp, 0, 1001 * 1001 * 4);

        dp[0][0] = 1;

        for(int K = 1; K <= k; ++K){
            int sum = 0;
            for(int j = minLength; j <= n; ++j){

                /// acumula las (k-1)-particiones validas tales que la particion k empieza en un primo
                if(prime(s[j - minLength] - '0'))
                    sum = (sum + dp[j - minLength][K - 1]) % MOD;

                /// si el digito actual no es primo, entonces la particion k valida
                if(!prime(s[j - 1] -'0'))
                    dp[j][K] = sum;
            }
        }

        return dp[n][k];
    }
};
