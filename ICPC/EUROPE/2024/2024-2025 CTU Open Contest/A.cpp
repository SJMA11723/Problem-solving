#include <bits/stdc++.h>

using namespace std;

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

const int MOD = 1e9 +7;

const int di[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dj[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const string order = "TUY#CIO#JVDKPWXELQZFMRGNSABH";
map<pii, char> dir2ch;
map<char, pii> ch2dir;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int idx = 0;
    for(int i = 0; i < 8; ++i){
        for(int j = i + 1; j < 8; ++j){
            ch2dir[order[idx]] = {i, j};
            dir2ch[{i, j}] = order[idx];
            idx++;
        }
    }

    int n, c; cin >> n >> c;
    for(int i = 0; i < n; ++i){
        char mat[9][9];
        for(int j = 0; j < 9; ++j)
        for(int k = 0; k < 9; ++k) cin >> mat[j][k];

        pii D = {-1, -1};
        for(int j = 0; j < 9; ++j)
        for(int k = 0; k < 9; ++k) if(mat[j][k] == '*'){
            for(int dir = 0; dir < 8; ++dir){
                int nj = j + di[dir];
                int nk = k + dj[dir];

                if(mat[nj][nk] == '#'){
                    if(D.fi == -1) D.fi = dir;
                    else D.se = dir;
                }
            }
        }

        char ch = dir2ch[D];
        ch = (ch - 'A' + c) % 26 + 'A';
        D = ch2dir[ch];

        memset(mat, '.', sizeof(mat));
        mat[4][4] = '*';
        int ni = 4, nj = 4;
        for(int k = 0; k < 3; ++k){
            ni += di[D.fi];
            nj += dj[D.fi];
            mat[ni][nj] = '#';
        }

        ni = 4, nj = 4;
        for(int k = 0; k < 3; ++k){
            ni += di[D.se];
            nj += dj[D.se];
            mat[ni][nj] = '#';
        }

        for(int j = 0; j < 9; ++j, cout << '\n')
        for(int k = 0; k < 9; ++k) cout << mat[j][k];
    }
}