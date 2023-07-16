class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int domIzq[100'000] = {}, domDer[100'000] = {}, maxFreq = 0, maxNum;
        map<int, int> cub;
        for(int i = 0; i < n; ++i){
            cub[nums[i]]++;
            if(cub[nums[i]] > maxFreq){
                maxFreq = cub[nums[i]];
                maxNum = nums[i];
            }
            if(maxFreq * 2 > i + 1) domIzq[i] = maxNum;
        }
        cub.clear();
        
        maxFreq = 0;
        for(int i = n - 1; 0 <= i; --i){
            cub[nums[i]]++;
            if(cub[nums[i]] > maxFreq){
                maxFreq = cub[nums[i]];
                maxNum = nums[i];
            }
            if(maxFreq * 2 > n - i) domDer[i] = maxNum;
        }
        
        for(int i = 0; i + 1 < n; ++i){
            if(domIzq[i] && domDer[i + 1] && domIzq[i] == domDer[i + 1]) return i;
        }
        
        return -1;
    }
};