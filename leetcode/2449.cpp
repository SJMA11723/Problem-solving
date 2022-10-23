class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long ans = 0;

        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());

        vector<int> par, impar, parT, imparT;
        par.reserve(n / 2);
        impar.reserve(n / 2);
        parT.reserve(n / 2);
        imparT.reserve(n / 2);

        for(int i = 0; i < n; ++i){
            if(nums[i] % 2) impar.push_back(nums[i]);
            else par.push_back(nums[i]);
        }

        for(int i = 0; i < n; ++i){
            if(target[i] % 2) imparT.push_back(target[i]);
            else parT.push_back(target[i]);
        }

        for(int i = 0; i < par.size(); ++i){
            if(parT[i] < par[i]) ans += (long long)(par[i] - parT[i]) / 2;
        }

        for(int i = 0; i < impar.size(); ++i){
            if(imparT[i] < impar[i]) ans += (long long)(impar[i] - imparT[i]) / 2;
        }

        return ans;
    }
};