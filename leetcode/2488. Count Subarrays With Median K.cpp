class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int pos, n = nums.size();
        for(int i = 0; i < n; ++i)
            if(nums[i] == k) pos = i;
        
        int ans = 0;
        map<int, int> right;
        
        int diff = 0;
        for(int i = pos; i < n; ++i){
            if(nums[i] < k) diff++;
            else if(nums[i] > k) diff--;
            right[diff]++;
        }
        
        diff = 0;
        for(int i = pos; 0 <= i; --i){
            if(nums[i] < k) diff++;
            else if(nums[i] > k) diff--;
            ans += right[-diff] + right[-1 - diff];
        }
        
        return ans;
    }
};