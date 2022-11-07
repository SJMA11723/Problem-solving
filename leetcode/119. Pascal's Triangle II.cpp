class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(2, vector<int>(rowIndex + 1));

        ans[0][0] = ans[1][0] = 1;

        for(int i = 1; i <= rowIndex; ++i){
            int fil = i % 2, prevFil = (i - 1) % 2;
            for(int j = 1; j < i; ++j){
                ans[fil][j] = ans[prevFil][j - 1] + ans[prevFil][j];
            }
            ans[fil][i] = 1;
        }

        
        return ans[rowIndex % 2];
    }
};