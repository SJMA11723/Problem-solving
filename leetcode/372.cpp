class Solution {
public:
    const int MOD = 1337;

    int bin_exp(int a, int b){
        if(!b) return 1;
        int tmp = bin_exp(a, b / 2);
        if(b & 1) return tmp * tmp % MOD * a % MOD;
        return tmp * tmp % MOD;
    }

    int superPow(int a, vector<int>& b) {
        int phimod = MOD;
        int tmp = MOD;
        for(int d = 2; d * d <= tmp; ++d){
            if(tmp % d) continue;
            while(tmp % d == 0) tmp /= d;
            phimod -= phimod / d;
        }
        if(tmp > 1) phimod -= phimod / tmp;

        int n = b.size();
        int pow10 = 1;
        int expb = 0;
        for(int i = n - 1; 0 <= i; --i){
            expb += b[i] * pow10 % phimod;
            if(expb >= phimod) expb -= phimod;
            pow10 = pow10 * 10 % phimod;
        }

        cout << phimod << ' ' << expb << '\n';

        return bin_exp(a % MOD, phimod * (__gcd(a, MOD) > 1) + expb);
    }
};