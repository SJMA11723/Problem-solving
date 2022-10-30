class Solution {
public:
    
    int sumDigits(long long x){
        int sum = 0;
        while(x){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    
    long long makeIntegerBeautiful(long long n, int target) {
        int sum = sumDigits(n);
        long long ans = 0, pot = 1;
        
        while(target < sum){
            int d = n % 10;
            n /= 10;
            
            ans += pot * (10 - d);
            
            n++;
            
            sum = sumDigits(n);
            pot *= 10;
        }
        
        return ans;
    }
};
