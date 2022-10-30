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
    
    int dfs(const TreeNode* root, int height, vector<pair<int, int>> maxHeights[], int heights[]){
        heights[root->val] = height;
               
        if(root->left == nullptr && root->right == nullptr){
            maxHeights[height].push_back({root->val, height});
            return height;
        }
        
        int maxi = height;
        
        if(root->left != nullptr){
            int h = dfs(root->left, height + 1, maxHeights, heights);
            
            maxi = max(maxi, h);
        }
        
        if(root->right != nullptr){
            int h = dfs(root->right, height + 1, maxHeights, heights);
            
            maxi = max(maxi, h);
        }
        
        maxHeights[height].push_back({root->val, maxi});
        
        return maxi;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<pair<int, int>> maxHeights[100005];
        int heights[100005] = {};
        
        int maxHeight = 0;
        dfs(root, 0, maxHeights, heights);
        
        
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for(int q : queries){
            int level = heights[q];
            
            int maxi = 0;
            for(auto it : maxHeights[level]){
                if(it.first == q) continue;
                maxi = max(maxi, it.second);
            }
            
            if(maxi) ans.push_back(maxi);
            else ans.push_back(level - 1);
        }
        
        return ans;
    }
};