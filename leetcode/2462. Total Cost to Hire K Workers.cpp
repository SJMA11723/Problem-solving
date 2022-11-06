class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int n = costs.size();
        
        priority_queue<int, vector<int>, greater<int>> left, right;
        
        int ini = 0, fin = n - 1;
        
        for(int i = 0; i < candidates; ++i){
            if(ini <= fin){
                left.push(costs[ini++]);
            }
            
            if(ini <= fin){
                right.push(costs[fin--]);
            }
        }
        
        while(k--){
            if(right.empty()){
                ans += left.top();
                left.pop();
                continue;
            }
            
            if(left.empty()){
                ans += right.top();
                right.pop();
                continue;
            }
            
            if(left.top() <= right.top()){
                ans += left.top();
                left.pop();
                    
                if(ini <= fin)
                    left.push(costs[ini++]);
            } else {
                ans += right.top();
                right.pop();
                
                if(ini <= fin)
                    right.push(costs[fin--]);
            }
        }
        
        return ans;
    }
};