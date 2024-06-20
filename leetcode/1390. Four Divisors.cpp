class Solution {
public:
    void criba(int n, vector<int> &lp){
        lp.clear();
        if(n < 2) return;

        lp.resize(n + 1);
        for(int i = 2; i <= n; i += 2) lp[i] = 2;

        for(long long i = 3; i <= n; i += 2){
            if(lp[i]) continue;
            lp[i] = i;
            for(long long j = i * i; j <= n; j += 2 * i)
                lp[j] = i;
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        vector<int> lp;
        criba(1e5 + 1, lp);

        int64_t ans = 0;
        for(int64_t x : nums){
            if(x < 2) continue;

            if(lp[x / lp[x]] == x / lp[x] && lp[x] != x / lp[x])
                ans += 1 + x + lp[x] + x / lp[x];
            int64_t cnt = 0, p = lp[x];
            while(x % p == 0){
                x /= p;
                cnt++;
            }

            if(x == 1 && cnt == 3) ans += (p * p * p * p - 1) / (p - 1);
        }

        return ans;
    }
};