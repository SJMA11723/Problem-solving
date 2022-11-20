class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            int lcm = nums[i];
            int gcd = nums[i];
            
            if(lcm == k) ans++;
            
            for(int j = i + 1; j < n; ++j){
                lcm = lcm * nums[j] / __gcd(lcm, nums[j]);
                if(lcm == k) ans++;
                else if(k < lcm) break;
            }
        }
        return ans;
    }
};