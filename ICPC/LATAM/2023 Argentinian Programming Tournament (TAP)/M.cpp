#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, T; cin >> N >> T;

    vector<int> P, NP;

    for(int i = 0; i < N; ++i){
        char c; cin >> c;
        int x; cin >> x;
        if(c == 'P') P.push_back(x);
        else NP.push_back(x);
    }

    sort(P.begin(), P.end());
    sort(NP.begin(), NP.end());

    long double time1 = 0, speed = T * 0.75;
    long double downloaded = 0;
    for(int i = 0; i < P.size(); ++i){
        time1 += (P[i] - downloaded) * (P.size() - i) / speed;
        downloaded = P[i];
    }

    downloaded = 0;
    long double time2 = 0;
    speed = T * 0.25;
    for(int i = 0; i < NP.size(); ++i){
        time2 += (NP[i] - downloaded) * (NP.size() - i) / speed;
        downloaded = NP[i];
    }

    //cout << "Times: " << time1 << ' ' << time2 << '\n';

    if(time2 < time1){
        speed = T * 0.75;
        swap(NP, P);
        swap(time1, time2);
    }

    bool ok = false;
    downloaded = 0;
    long double ans = 0;
    for(int i = 0; i < NP.size(); ++i){
        long double tmp_time = (NP[i] - downloaded) * (NP.size() - i) / speed;
        if(ans + tmp_time >= time1 && !ok){
            /// Descarga hasta que termina P
            ok = true;
            long double tmp_D = (time1 - ans) * speed / (NP.size() - i);
            ans = time1;

            /// Descarga con toda la velocidad
            speed = T;
            //cout << NP[i] - downloaded << ' ' << tmp_D << ' ' << ans << ' ' << speed << '\n';
            ans += (NP[i] - downloaded - tmp_D) * (NP.size() - i) / speed;
            //cout << ans << '\n';
        } else ans += tmp_time;
        downloaded = NP[i];
    }

    cout << fixed << setprecision(5) << ans << '\n';

    return 0;
}
