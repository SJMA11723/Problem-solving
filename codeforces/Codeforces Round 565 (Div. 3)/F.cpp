/**
* Author: Jorge Raul Tzab Lopez
* Github: https://github.com/SJMA11723
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    int64_t dp[2][10];
    fill(dp[0], dp[0] + 10, LLONG_MIN);
    dp[0][0] = 0;

    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        int64_t card11 = 0, card12 = 0, card13 = 0;
        int64_t card2 = 0, card3 = 0;
        while(k--){
            int64_t c, d; cin >> c >> d;
            if(c == 1){
                if(d >= card11){
                    card13 = card12;
                    card12 = card11;
                    card11 = d;
                } else if(d >= card12){
                    card13 = card12;
                    card12 = d;
                } else if(d > card13) card13 = d;
            } else if(c == 2) card2 = max(card2, d);
            else card3 = max(card3, d);
        }

        /// using 0 cards
        for(int j = 0; j < 10; ++j) dp[i % 2][j] = dp[(i - 1) % 2][j];

        /// using 1 card
        int64_t damage = max({card11, card2, card3});

        for(int j = 1; j < 10; ++j) dp[i % 2][j] = max(dp[i % 2][j], damage + dp[(i - 1) % 2][j - 1]);
        dp[i % 2][0] = max(dp[i % 2][0], dp[(i - 1) % 2][9] + 2 * damage);

        /// using 2 cards
        damage = 0;
        int64_t maxi = 0;
        if(card2 && card11) damage = card2 + card11, maxi = max(card11, card2);
        if(card11 && card12 && damage < card11 + card12) damage = card11 + card12, maxi = max(card11, card12);

        if(damage){
            for(int j = 2; j < 10; ++j) dp[i % 2][j] = max(dp[i % 2][j], damage + dp[(i - 1) % 2][j - 2]);
            dp[i % 2][0] = max(dp[i % 2][0], dp[(i - 1) % 2][8] + damage + maxi);
            dp[i % 2][1] = max(dp[i % 2][1], dp[(i - 1) % 2][9] + damage + maxi);
        }

        /// using 3 cards
        damage = 0;
        maxi = 0;
        if(card11 && card12 && card13) damage = card11 + card12 + card13, maxi = max({card11, card12, card13});

        if(damage){
            for(int j = 3; j < 10; ++j) dp[i % 2][j] = max(dp[i % 2][j], damage + dp[(i - 1) % 2][j - 3]);
            dp[i % 2][0] = max(dp[i % 2][0], dp[(i - 1) % 2][7] + damage + maxi);
            dp[i % 2][1] = max(dp[i % 2][1], dp[(i - 1) % 2][8] + damage + maxi);
            dp[i % 2][2] = max(dp[i % 2][2], dp[(i - 1) % 2][9] + damage + maxi);
        }

        //cout << "Turno " << i << '\n';
        //for(int j = 0; j < 10; ++j){
        //    cout << "Usando " << j << " cartas: " << dp[i % 2][j] << '\n';
        //}
    }

    cout << *max_element(dp[n % 2], dp[n % 2] + 10) << '\n';
}
