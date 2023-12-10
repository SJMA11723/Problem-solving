class Solution {
public:
    int bin_exp(int a, int b, const int MOD){
        if(!b) return 1;
        a %= MOD;
        int tmp = bin_exp(a, b / 2, MOD);
        if(b % 2) return tmp * tmp % MOD * a % MOD;
        return tmp * tmp % MOD;
    }
    
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for(int i = 0; i < variables.size(); ++i)
            if(bin_exp(bin_exp(variables[i][0], variables[i][1], 10), variables[i][2], variables[i][3]) == target)
                ans.push_back(i);
        return ans;
    }
};