class Solution {
public:
    int climbStairs(int n) {
        /**
            note that for each step n, you can reach
            the nth step from step n - 1 and step n - 2.
            This is ans(n) = ans(n - 1) + ans(n - 2).
            Then the answer is the nth fibonacci number.

            - ans(0) = ans(1) = 1
        */

        if(n < 2) return 1;

        int ans = 1, prev = 1;

        for(int i = 2; i <= n; ++i){
            ans += prev;
            prev = ans - prev;
        }

        return ans;
    }
};