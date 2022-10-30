class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        map<string, long long> pop;
        map<string, priority_queue<pair<int, string>, vector<pair<int, string> >, greater< pair<int, string> > > > vids;
        long long maxPop = 0;
        
        vector<vector<string>> ans;
        
        
        for(int i = 0; i < n; ++i){
            vids[ creators[i] ].push({-views[i], ids[i]});
            pop[ creators[i] ] += views[i];
            
            maxPop = max(maxPop, pop[ creators[i] ]);
        }
        
        for(pair<string, long long> it : pop){
            if(it.second != maxPop) continue;
            
            ans.push_back({it.first, vids[it.first].top().second});
        }
        
        return ans;
    }
};