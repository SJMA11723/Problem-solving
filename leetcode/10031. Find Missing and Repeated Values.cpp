class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        int n = grid.size();
        int cub[50 * 50 + 1] = {};
        for(vector<int> &f : grid){
            for(int num : f){
                cub[num]++;
                if(cub[num] == 2) ans[0] = num;
            }
        }
        for(int i = 1; i <= n * n; ++i)
            if(!cub[i]){
                ans[1] = i;
                break;
            }
        return ans;
    }
};