#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int L, C; cin >> L >> C;
    char mat[L][C];
    for(int i = 0; i < L; ++i){
        for(int j = 0; j < C; ++j) cin >> mat[i][j];
    }

    int mask[L][C];
    memset(mask, 0, sizeof(mask));

    int n; cin >> n;
    for(int P = 0; P < n; ++P){
        string s; cin >> s;

        int cnt[27] = {};
        for(char c : s) cnt[c - 'A']++;

        int k = s.size();
        /// Horizontal
        for(int i = 0; i < L; ++i){
            int cnt2[27] = {};

            /// primera ventana
            for(int j = 0; j < min(C, k); ++j)
                cnt2[mat[i][j] - 'A']++;

            int diff = 0;
            for(int c = 0; c < 27; ++c)
                diff += cnt[c] != cnt2[c];

            /// si son iguales entonces cuenta agrega palabra
            if(!diff){
                for(int j = 0; j < min(C, k); ++j)
                    mask[i][j] |= (1 << P);
            }

            for(int j = k; j < C; ++j){
                int x = mat[i][j - k] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]--;
                if(cnt[x] == cnt2[x]) diff--;

                x = mat[i][j] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]++;
                if(cnt[x] == cnt2[x]) diff--;

                if(!diff){
                    for(int idx = j - k + 1; idx <= j; ++idx)
                        mask[i][idx] |= (1 << P);
                }
            }
        }

        /// Vertical
        for(int j = 0; j < C; ++j){
            int cnt2[27] = {};

            /// primera ventana
            for(int i = 0; i < min(L, k); ++i)
                cnt2[mat[i][j] - 'A']++;

            int diff = 0;
            for(int c = 0; c < 27; ++c)
                diff += cnt[c] != cnt2[c];

            /// si son iguales entonces cuenta agrega palabra
            if(!diff){
                for(int i = 0; i < min(L, k); ++i)
                    mask[i][j] |= (1 << P);
            }

            for(int i = k; i < L; ++i){
                int x = mat[i - k][j] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]--;
                if(cnt[x] == cnt2[x]) diff--;

                x = mat[i][j] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]++;
                if(cnt[x] == cnt2[x]) diff--;

                if(!diff){
                    for(int idx = i - k + 1; idx <= i; ++idx)
                        mask[idx][j] |= (1 << P);
                }
            }
        }

        /// Diagonales inferiores
        for(int i = 0; i < L; ++i){
            int len = min(C, L - i);

            int cnt2[27] = {}; /// izq
            int cnt3[27] = {}; /// der

            /// primera ventana
            for(int j = 0; j < min(len, k); ++j){
                cnt2[mat[i + j][j] - 'A']++;
                cnt3[mat[i + j][C - 1 - j] - 'A']++;
            }

            int diff = 0, diff1 = 0;
            for(int c = 0; c < 27; ++c){
                diff += cnt[c] != cnt2[c];
                diff1 += cnt[c] != cnt3[c];
            }

            /// si son iguales entonces cuenta agrega palabra
            if(!diff){
                for(int j = 0; j < min(len, k); ++j)
                    mask[i + j][j] |= (1 << P);
            }

            if(!diff1){
                for(int j = 0; j < min(len, k); ++j)
                    mask[i + j][C - 1 - j] |= (1 << P);
            }

            for(int j = k; j < len; ++j){
                /// izq
                int x = mat[i + j - k][j - k] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]--;
                if(cnt[x] == cnt2[x]) diff--;

                x = mat[i + j][j] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]++;
                if(cnt[x] == cnt2[x]) diff--;

                if(!diff){
                    for(int idx = 0; idx < k; ++idx)
                        mask[i + j - idx][j - idx] |= (1 << P);
                }

                /// der
                x = mat[i + j - k][C - 1 - j + k] - 'A';
                if(cnt[x] == cnt3[x]) diff1++;
                cnt3[x]--;
                if(cnt[x] == cnt3[x]) diff1--;

                x = mat[i + j][C - 1 - j] - 'A';
                if(cnt[x] == cnt3[x]) diff1++;
                cnt3[x]++;
                if(cnt[x] == cnt3[x]) diff1--;

                if(!diff1){
                    for(int idx = 0; idx < k; ++idx)
                        mask[i + j - idx][C - 1 - j + idx] |= (1 << P);
                }
            }
        }


        /// Diagonales superiores
        for(int j = 1; j < C; ++j){
            int len = min(L, C - j);

            int cnt2[27] = {}; /// izq
            int cnt3[27] = {}; /// der

            /// primera ventana
            for(int i = 0; i < min(len, k); ++i){
                cnt2[mat[i][j + i] - 'A']++;
                cnt3[mat[i][C - 1 - j - i] - 'A']++;
            }

            int diff = 0, diff1 = 0;
            for(int c = 0; c < 27; ++c){
                diff += cnt[c] != cnt2[c];
                diff1 += cnt[c] != cnt3[c];
            }

            /// si son iguales entonces cuenta agrega palabra
            if(!diff){
                for(int i = 0; i < min(len, k); ++i)
                    mask[i][j + i] |= (1 << P);
            }

            if(!diff1){
                for(int i = 0; i < min(len, k); ++i)
                    mask[i][C - 1 - j - i] |= (1 << P);
            }

            for(int i = k; i < len; ++i){
                /// izq
                int x = mat[i - k][j + i - k] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]--;
                if(cnt[x] == cnt2[x]) diff--;

                x = mat[i][j + i] - 'A';
                if(cnt[x] == cnt2[x]) diff++;
                cnt2[x]++;
                if(cnt[x] == cnt2[x]) diff--;

                if(!diff){
                    for(int idx = 0; idx < k; ++idx)
                        mask[i - idx][j + i - idx] |= (1 << P);
                }

                /// der
                x = mat[i - k][C - 1 - j - i + k] - 'A';
                if(cnt[x] == cnt3[x]) diff1++;
                cnt3[x]--;
                if(cnt[x] == cnt3[x]) diff1--;

                x = mat[i][C - 1 - j - i] - 'A';
                if(cnt[x] == cnt3[x]) diff1++;
                cnt3[x]++;
                if(cnt[x] == cnt3[x]) diff1--;

                if(!diff1){
                    for(int idx = 0; idx < k; ++idx)
                        mask[i - idx][C - 1 - j - i + idx] |= (1 << P);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < L; ++i)
        for(int j = 0; j < C; ++j)
            ans += __builtin_popcount(mask[i][j]) >= 2;
    cout << ans << '\n';
}
