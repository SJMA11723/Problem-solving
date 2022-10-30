class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, con = 0;
        for(int it : nums)
            if(it % 6 == 0){
                sum += it;
                con++;
            }
        
        if(con == 0) return 0;
        return sum / con;
    }
};