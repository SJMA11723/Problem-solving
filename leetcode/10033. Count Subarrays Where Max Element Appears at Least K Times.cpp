class Solution {
public:
    long long subarrays(long long n){
        return (n * n + n) / 2;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        long long n = nums.size();
        long long ans = (n * n + n) / 2;

        int maxi = *max_element(nums.begin(), nums.end());

        int ptr = 0;
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            cnt += nums[i] == maxi;
            while(cnt >= k) cnt -= nums[ptr++] == maxi;
            ans -= i - ptr + 1;
        }
        return ans;
    }
};
