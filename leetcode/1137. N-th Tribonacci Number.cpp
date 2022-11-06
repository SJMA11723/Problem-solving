class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        else if(n == 2) return 1;

        int trib = 2, prev = 1, prev2 = 1;
        while(3 < n--){
            /// trib: T(n), prev: T(n - 1), prev2: T(n - 2)
            trib += prev + prev2; ///T(n) + T(n - 1) + T(n - 2) = T(n + 1)
            prev = trib - prev - prev2; /// T(n + 1) - T(n - 1) - T(n - 2) = T(n)
            prev2 = trib - prev - prev2; /// T(n + 1) - T(n) - T(n - 2) = T(n - 1)
        }

        return trib;
    }
};
