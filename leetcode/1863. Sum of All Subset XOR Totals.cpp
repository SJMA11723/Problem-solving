class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int lim = 1 << nums.size();
        for(int i = 1; i < lim; ++i){
            int x = 0;
            for(int j = 0; j < nums.size(); ++j){
                if(i & (1 << j)) x ^= nums[j];
            }
            ans += x;
        }
        return ans;
    }
};
