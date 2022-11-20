class Solution {
public:
    
    pair<long long, int> dfs(int root, vector<int> grafo[], bitset<100000> &visitado, const int &seats){
        if(visitado[root]) return {0, 0};
        
        visitado[root] = 1;
        
        pair<long long, int> ans = {0, 1};
        
        for(int it : grafo[root]){
            pair<long long, int> a = dfs(it, grafo, visitado, seats);
            ans.first += a.first;
            ans.second += a.second;
        }
        
        if(root)
            ans.first += (ans.second + seats - 1) / seats;
        return ans;
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<int> grafo[100000];
        bitset<100000> visitado;
        
        for(int i = 0; i < roads.size(); ++i){
            int a = roads[i][0], b = roads[i][1];
            grafo[a].push_back(b);
            grafo[b].push_back(a);
        }
        
        return dfs(0, grafo, visitado, seats).first;
    }
};