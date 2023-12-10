class Solution {
public:
    int countTestedDevices(vector<int>& arr) {
        int ans = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(arr[i] - ans > 0) ans++;
        }
        return ans;
    }
};