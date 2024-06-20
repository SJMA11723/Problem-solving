class Solution {
public:
    void criba(int n, vector<int> &primos){
        primos.clear();
        if(n < 2) return;

        vector<bool> no_primo(n + 1);
        no_primo[0] = no_primo[1] = true;

        for(long long i = 3; i * i <= n; i += 2){
            if(no_primo[i]) continue;
            for(long long j = i * i; j <= n; j += 2 * i)
                no_primo[j] = true;
        }

        primos.push_back(2);
        for(int i = 3; i <= n; i += 2){
            if(!no_primo[i])
                primos.push_back(i);
        }
    }

    int cuentaPrimos(int n){
        if(n < 2) return 0;

        const int S = sqrt(n);

        vector<int> primosRaiz;
        criba(sqrt(n) + 1, primosRaiz);

        int ans = 0;

        vector<char> no_primo(S + 1);
        for(int ini = 0; ini <= n; ini += S){
            fill(no_primo.begin(), no_primo.end(), false);
            for(int p : primosRaiz){
                int m = p * max(p, (ini + p - 1) / p) - ini;
                for(; m <= S; m += p)
                    no_primo[m] = true;
            }

            for(int i = 0; i < S && i + ini <= n; ++i)
                if(!no_primo[i] && 1 < i + ini)
                    ans++;
        }

        return ans;
    }

    int countPrimes(int n) {
        return cuentaPrimos(n - 1);
    }
};
