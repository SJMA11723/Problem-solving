#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int f; cin >> f;
    int cnt[4] = {}, ans = 0; /// RD = 0, DD = 1, RR = 2, DR = 3
    int can_move_RD = 0;
    for(int i = 0; i < f; ++i){
        string s; cin >> s;
        string tmp;
        bool D, R;
        for(char c : s)
        if(c == 'D'){
            tmp += c;
            D = true;
        } else if(c == 'R'){
            tmp += c;
            R = true;
        }

        float DD, DR, RD, RR;
        DD = DR = RD = RR = 0;

        float len, lenDD, lenDR, lenRD, lenRR;
        char prv;

        /// Cuenta DD, DR
        prv = 'R';
        len = 0;
        for(int j = 0; j < tmp.size(); ++j){
            if(tmp[j] != prv){
                prv = tmp[j];
                len++;
            }
        }
        lenDD = prv == 'D' ? len : len - 1;
        lenDR = prv == 'D' ? len - 1 : len;
        DD = (prv == 'D' ? len - 1 : len - 2) / 2;
        DR = (prv == 'R' ? len : len - 1) / 2;

        /// Cuenta RD, RR
        prv = 'D';
        len = 0;
        for(int j = 0; j < tmp.size(); ++j){
            if(tmp[j] != prv){
                prv = tmp[j];
                len++;
            }
        }
        lenRD = prv == 'D' ? len : len - 1;
        lenRR = prv == 'D' ? len - 1 : len;
        RD = (prv == 'D' ? len - 2 : len - 3) / 2;
        RR = (prv == 'R' ? len - 1 : len - 2) / 2;

        float maxi = max({DD, DR, RD, RR});

        if(maxi == RD && lenRD >= 2){
            cnt[0]++;
            if(lenRD >= 4) can_move_RD++;
        } else if(maxi == DD && lenDD >= 1) cnt[1]++;
        else if(maxi == RR && lenRR >= 1) cnt[2]++;
        else if(maxi == DR && lenDR >= 2) cnt[3]++;
        else maxi = 0;
        ans += (int)maxi;
    }

    /// iguala cnt[1] con cnt[2]
    int move = min(can_move_RD, abs(cnt[1] - cnt[2]));
    cnt[0] -= move;
    can_move_RD -= move;
    if(cnt[1] <= cnt[2]) cnt[1] += move;
    else cnt[2] += move;

    int cnt_comp1 = cnt[0] + min(cnt[1], cnt[2]) + (cnt[0] > 0 && min(cnt[1], cnt[2]) > 0);

    ans += max(0, cnt_comp1 - (cnt[0] > 0));

    cout << ans << '\n';
}
