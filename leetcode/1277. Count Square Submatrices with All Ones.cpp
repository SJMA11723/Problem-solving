class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 1; i < n; ++i)
            matrix[i][0] += matrix[i - 1][0];
        
        for(int i = 1; i < m; ++i)
            matrix[0][i] += matrix[0][i - 1];

        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                matrix[i][j] += matrix[i][j - 1] + matrix[i - 1][j] - matrix[i - 1][j - 1];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                for(int k = 0; i + k < n && j + k < m; ++k){
                    int sum = matrix[i + k][j + k];
                    if(i) sum -= matrix[i - 1][j + k];
                    if(j) sum -= matrix[i + k][j - 1];
                    if(i && j) sum += matrix[i - 1][j - 1];

                    if(sum == (k + 1) * (k + 1)) ans++;
                }
            }
        }

        return ans;
    }
};