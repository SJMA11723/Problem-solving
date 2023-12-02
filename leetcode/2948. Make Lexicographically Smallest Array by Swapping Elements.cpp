class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        pair<int, int> ord[n + 1];
        for(int i = 0; i < n; ++i){
            ord[i] = {nums[i], i};
        }
        ord[n] = {INT_MAX, INT_MAX};
        sort(ord, ord + n + 1);
        
        int ant = ord[0].first;
        priority_queue<int, vector<int>, greater<int>> indices;
        queue<int> changes;
        for(int i = 0; i <= n; ++i){
            if(ord[i].first - ant > limit){
                while(indices.size()){
                    nums[indices.top()] = changes.front();
                    indices.pop();
                    changes.pop();
                }
            }
            indices.push(ord[i].second);
            changes.push(ord[i].first);
            ant = ord[i].first;
        }
        
        return nums;
    }
};