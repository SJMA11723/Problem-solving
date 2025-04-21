class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int64_t l = 1, r = INT_MAX;
        while(l < r){
            int64_t mid = l + (r - l) / 2;
            int64_t cnt_ugly = mid / a + mid / b + mid / c;
            cnt_ugly -= mid / (1ll * a / __gcd(a, b) * b);
            cnt_ugly -= mid / (1ll * a / __gcd(a, c) * c);
            cnt_ugly -= mid / (1ll * b / __gcd(b, c) * c);
            int64_t lcm_ab = 1ll * a / __gcd(a, b) * b;
            cnt_ugly += mid / (lcm_ab / __gcd(lcm_ab, (int64_t)c) * c);

            if(cnt_ugly >= n) r = mid;
            else l = mid + 1;
        }

        return l;
    }
};