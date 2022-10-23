class Solution {
public:
    long long eval(vector<int>& nums, vector<int>& cost, long long x){
        long long ret = 0;
        for(int i = 0; i < nums.size(); ++i){
            ret += abs((long long)nums[i] - x) * (long long)cost[i];
        }
        return ret;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ini = 1e9;
        long long fin = 0;
        long long costo = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            ini = min(ini, (long long)nums[i]);
            fin = max(fin, (long long)nums[i]);
        }
        
        while(ini <= fin){
            long long mitad = (ini + fin) / 2;
            long long ant = mitad - 1, sig = mitad + 1;
            
            long long evalMitad = eval(nums, cost, mitad);
            long long evalAnt = eval(nums, cost, ant);
            long long evalSig = eval(nums, cost, sig);
            
            //cout << ini << ' ' << fin << ' ' << mitad << " | " << evalAnt << ' ' << evalMitad << ' ' << evalSig << '\n';
            
            if(evalAnt < evalMitad && evalMitad < evalSig) fin = ant;
            else if(evalSig < evalMitad && evalMitad < evalAnt) ini = sig;
            else {
                costo = evalMitad;
                break;
            }
        }
        return costo;
    }
};