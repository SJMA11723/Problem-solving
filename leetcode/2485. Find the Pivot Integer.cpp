class Solution {
public:
    int pivotInteger(int n) {
        int S = n * (n + 1) / 2, sum = 1;
        for(int i = 1; i <= n; ++i){
            if(S == sum) return i;
            sum += i + 1;
            S -= i;
        }
        return -1;
    }
};