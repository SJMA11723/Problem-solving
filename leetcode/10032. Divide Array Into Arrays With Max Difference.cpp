class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if(nums.size() % 3) return {};
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for(int i = 2; i < n; i += 3){
            if(abs(nums[i] - nums[i - 2]) > k) return {};
            ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }
        
        return ans;
    }
};