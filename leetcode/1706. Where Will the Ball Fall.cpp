class Solution {
public:    
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans(n);

        for(int i = 0; i < n; ++i){
            int fil, col = i;
            for(fil = 0; fil < m; ++fil){
                if(grid[fil][col] == 1){
                    if(col + 1 == n || grid[fil][col + 1] == -1) break;
                    col++;
                } else {
                    if(col == 0 || grid[fil][col - 1] == 1) break;
                    col--;
                }
            }

            if(fil == m) ans[i] = col;
            else ans[i] = -1;
        }

        return ans;
    }
};