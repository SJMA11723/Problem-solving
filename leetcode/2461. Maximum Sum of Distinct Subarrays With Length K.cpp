class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        int n = nums.size();
        
        bitset<100002> ap;
        int ini = 0, fin = 0;
        while(fin < n){
            while(ap[ nums[fin] ]){
                sum -= nums[ini];
                ap[nums[ini]] = 0;
                ini++;
            }
            
            if(fin - ini == k){
                sum -= nums[ini];
                ap[ nums[ini] ] = 0;
                ini++;
            }

            sum += nums[fin];
            ap[ nums[fin++] ] = 1;
            
            if(fin - ini == k) ans = max(ans, sum);
        }
        
        return ans;
    }
};