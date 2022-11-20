/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* root, vector<vector<int>> &levels, int level = 0){
        if(root == nullptr) return;
        
        if(level == levels.size()){
            levels.push_back(vector<int>(1, root->val));
        } else levels[level].push_back(root->val);
        
        dfs(root->left, levels, level + 1);
        dfs(root->right, levels, level + 1);
    }
    
    int minSort(vector<int> &arr, const vector<int> &sorted, vector<bool> &ap, int pos){
        ap[pos] = true;
        
        int posS = lower_bound(sorted.begin(), sorted.end(), arr[pos]) - sorted.begin();
        if(!ap[ posS ]) return 1 + minSort(arr, sorted, ap, posS);
        return 0;
    }
    
    int minimumOperations(TreeNode* root) {
        vector<vector<int>> levels, sorted;
        dfs(root, levels);
        
        sorted = levels;
        int ans = 0;
        for(int i = 0; i < sorted.size(); ++i){
            sort(sorted[i].begin(), sorted[i].end());
            vector<bool> ap(sorted[i].size(), false);
            
            for(int j = 0; j < levels[i].size(); ++j){
                if(ap[j]) continue;
                ans += minSort(levels[i], sorted[i], ap, j);
            }
        }
        
        return ans;
    }
};