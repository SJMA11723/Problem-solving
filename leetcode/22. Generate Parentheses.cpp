class Solution {
public:

    void generate(int n, string act, int stack, vector<string> &ans){
        if(stack < 0) return;
        
        if(n == 1){
            if(stack == 1) ans.push_back(act + ")");
            return;
        }

        generate(n - 1, act + "(", stack + 1, ans);
        generate(n - 1, act + ")", stack - 1, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        generate(2 * n, "", 0, ans);

        return ans;
    }
};