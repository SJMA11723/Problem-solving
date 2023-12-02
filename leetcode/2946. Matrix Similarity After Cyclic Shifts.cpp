class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if((i % 2 && mat[i][j] != mat[i][(j + k) % m]) ||
                  (i % 2 == 0 && mat[i][j] != mat[i][(m + j - k) % m])){
                    return false;
                }
            }
        }
        return true;
    }
};