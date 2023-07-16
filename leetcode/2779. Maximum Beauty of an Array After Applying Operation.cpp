#define MAXN 200'005
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int cub[MAXN] = {};
        int ans = 0;
        for(int i = 0; i < n; ++i){
            nums[i]++;
            cub[ nums[i] ]++;
        }
        for(int i = 1; i < MAXN; ++i) cub[i] += cub[i - 1];
        for(int i = 0; i < MAXN; ++i){
            ans = max(ans, cub[min(MAXN - 1, i + k)] - cub[max(0, i - k - 1)]);
        }
        return ans;
    }
};