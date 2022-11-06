class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int maxi = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            nums[i] += 5e5;
            maxi = max(maxi, nums[i]);
        }

        int *bucket = new int[maxi + 1];
        memset(bucket, 0, (maxi + 1) * sizeof(int));

        for(int it : nums)
            bucket[it]++;
        
        for(int i = 0, con = 0; i <= maxi; ++i){
            while(bucket[i]){
                nums[con++] = i - 5e5;
                bucket[i]--;
            }
        }

        delete[] bucket;
        return nums;
    }
};