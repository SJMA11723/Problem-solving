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
    void dfs(TreeNode* root, vector<int> &nums){
        if(root == nullptr) return;
        
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        nums.reserve(100000);
        
        dfs(root, nums);
        
        int n = queries.size();
        vector<vector<int>> ans(n, vector<int>(2));
        for(int i = 0; i < n; ++i){
            int pos = lower_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
            
            if(pos == nums.size()){
                ans[i] = {nums[pos - 1], -1};
                continue;
            }
            
            if(nums[pos] == queries[i]) ans[i] = {nums[pos], nums[pos]};
            else if(pos == 0){
                ans[i] = {-1, nums[pos]};
            } else ans[i] = {nums[pos - 1], nums[pos]};
        }
        return ans;
    }
};